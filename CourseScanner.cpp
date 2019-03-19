//
// Created by Shein Htike on 2019-03-12.
//

#include "CourseScanner.h"
#include "Course.h"

#define CLASS_REGEX_PATTERN "([A-Z]{2,5}) (\\d{5})-(\\w+)\\n(\\w+) \\((\\d+)\\)\\n((?:(?:[A-Z][a-z])+ \\d{1,2}:\\d{2}(?:(?:AM)|(?:PM)) - \\d{1,2}:\\d{2}(?:(?:AM)|(?:PM))\\n(?:\\S+ )+(?:\\S+)\\n{0,1})+)"
#define CLASS_TIME_REGEX "((?:[A-Z][a-z])+) (\\d{1,2}):(\\d{2})((?:AM)|(?:PM)) - (\\d{1,2}):(\\d{2})((?:AM)|(?:PM))\\n(\\S+) (\\S+)"

//Returns a vector of string matches from an input string
auto CourseScanner::scanCourseStrings(const std::string &input) {
	std::regex pattern(CLASS_REGEX_PATTERN);
	std::sregex_iterator iterator{input.begin(), input.end(), pattern};
	const std::sregex_iterator end;
	std::vector<std::smatch> courseStrings;
	while (iterator != end) {
		courseStrings.push_back(*iterator);
		iterator++;
	}
	return courseStrings;
}

//Makes a unique pointer to a course::time object
auto CourseScanner::makeTime(const std::string &hour, const std::string &minute, const std::string &ampm) {
	auto hr = std::stoul(hour);
	auto mn = std::stoul(minute);
	if (ampm != "AM")
		hr += 12;
	return std::make_unique<Course::Time>(hr, mn);
}

//Returns a vector of Course::Meeting's from input
auto CourseScanner::scanCourseTimes(const std::string::const_iterator &stringStart, const std::string::const_iterator &stringEnd) {
	std::regex pattern(CLASS_TIME_REGEX);
    std::sregex_iterator iterator{stringStart, stringEnd, pattern};
	const std::sregex_iterator end;
	std::vector<Course::Meeting> courseTimes;
	while (iterator != end) {
		courseTimes.emplace_back();
		Course::Meeting &meeting = *(courseTimes.end() - 1);
		auto match = *iterator;
		iterator++;
		std::string daysString = match[1].str();
		int numSubstrings = daysString.size() / 2;
		std::vector<std::string> days(numSubstrings);
		for (auto day : days) {
			auto loc = std::find(daysOfWeek.begin(), daysOfWeek.end(), day);
			auto index = std::distance(daysOfWeek.begin(), loc);
			meeting.weekday[index] = true;
		}
		auto startTime = makeTime(match[2].str(), match[3].str(), match[4].str());
		auto endTime = makeTime(match[5].str(), match[6].str(), match[7].str());
		meeting.start = *startTime;
		meeting.end = *endTime;
		meeting.building = match[8].str();
		meeting.room = match[9].str();
	}
	return courseTimes;
}

auto CourseScanner::smatchToCourse(const std::smatch &match) {
    const std::string dept = match[1].str();
    const auto courseNum = std::stoul(match[2].str());
    const std::string courseType = match[3].str();
    const std::string section = match[4].str();
    const std::string courseID = match[5].str();
    const auto times = match[6];
    auto courseTimes = scanCourseTimes(times.first,times.second);
	auto pointer = std::make_unique<Course>(dept, courseNum, courseType, section, courseID, courseTimes);
	return pointer;
}

std::vector<Course> CourseScanner::scanCourses(const std::string &input) {
	auto matches = scanCourseStrings(input);
	if (matches.empty()) {
		throw CourseScanner::Exception("No courses found.");
	}
	std::vector<Course> courses;
	std::for_each(matches.begin(), matches.end(), [&courses](auto x) {
		auto coursePtr = smatchToCourse(x);
		courses.push_back(*coursePtr);
	});
	return courses;
}

bool CourseScanner::isValidCourseString(const std::string &input) {
	return !(scanCourseStrings(input).empty());
}

CourseScanner::Exception::Exception(const std::string &msg) : runtime_error(msg) {
}
