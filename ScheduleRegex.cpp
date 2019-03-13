//
// Created by Shein Htike on 2019-03-12.
//

#include "ScheduleRegex.h"
#include <vector>
#include <iostream>
const std::string &Course::getDepartment() const {
	return department;
}

unsigned int Course::getCourseNum() const {
	return courseNum;
}

const std::string &Course::getSection() const {
	return section;
}

Course::Course(const std::string &department, const unsigned int courseNum, const std::string &type,
			   const std::string &section, const std::string &courseID, const std::vector<Course::Meeting> &meetings)
		: department(department), courseNum(courseNum), type(type), section(section), courseID(courseID),
		  meetings(meetings) {}

Course::Meeting::Meeting() {
	std::fill(weekday.begin(),weekday.end(),false);
}

std::ostream &operator<<(std::ostream &os, const Course::Meeting &meeting) {
    os << "Days: ";
    for(int i=0; i < 7; i++){
        if(meeting.weekday[i])
            os << i << " ";
    }
	os << " start: " << meeting.start << " end: " << meeting.end << " building: "
	   << meeting.building << " room: " << meeting.room;
	return os;
}

Course::Time::Time(unsigned int hour, unsigned int minute) : hour(hour), minute(minute) {}

std::ostream &operator<<(std::ostream &os, const Course::Time &time1) {
	os << "hour: " << time1.hour << " minute: " << time1.minute;
	return os;
}

std::ostream &operator<<(std::ostream &os, const Course &course) {
	os << "department: " << course.department << " courseNum: " << course.courseNum << " type: " << course.type
	   << " section: " << course.section << " courseID: " << course.courseID << " meetings: ";
	for(auto m : course.meetings){
	    os << m << '\n';
	}
	return os;
}



//Returns a vector of string matches from an input string
auto CourseScanner::scanCourseStrings(const std::string& input){
    std::regex pattern(CLASS_REGEX_PATTERN);
    std::sregex_iterator iterator{input.begin(),input.end(),pattern};
    const std::sregex_iterator end;
    std::vector<std::smatch> courseStrings{7};
    while(iterator != end) {
        courseStrings.push_back(*iterator);
        iterator++;
    }
    return courseStrings;
}

//Makes a unique pointer to a course::time object
auto CourseScanner::makeTime(const std::string& hour, const std::string& minute, const std::string& ampm){
    auto hr = (unsigned int)std::stoi(hour);
    auto mn = (unsigned int)std::stoi(minute);
    if(ampm != "AM")
        hr+= 12;
    return std::make_unique<Course::Time>(hr,mn);
}
//Returns a vector of Course::Meeting's from input
auto CourseScanner::scanCourseTimes(const std::string& input){
    std::regex pattern(CLASS_TIME_REGEX);
    std::sregex_iterator iterator{input.begin(),input.end(),pattern};
    const std::sregex_iterator end;
    std::vector<Course::Meeting> courseTimes{5};
    while(iterator != end) {
        courseTimes.emplace_back();
        Course::Meeting& meeting = *(courseTimes.end() - 1);
        auto match = *iterator;
        iterator++;
        std::string daysString = match[1].str();
        int numSubstrings = daysString.size() / 2;
        std::vector<std::string> days(numSubstrings);
        for(auto day : days) {
            auto loc = std::find(daysOfWeek.begin(), daysOfWeek.end(), day);
            auto index = std::distance(daysOfWeek.begin(), loc);
            meeting.weekday[index] = true;
        }
        auto startTime = makeTime(match[2].str(),match[3].str(),match[4].str());
        auto endTime = makeTime(match[5].str(),match[6].str(),match[7].str());
        meeting.start = *startTime;
        meeting.end = *endTime;
        meeting.building = match[8].str();
        meeting.room = match[9].str();
    }
    return courseTimes;
}

auto CourseScanner::smatchToCourse(const std::smatch& match){
    std::string dept = match[1].str();
    auto courseNum = std::stoul(match[2].str());
    std::string courseType = match[3].str();
    std::string section = match[4].str();
    std::string courseID = match[5].str();
    auto courseTimes = scanCourseTimes(match[6].str());
    auto pointer = std::make_unique<Course>(dept,courseNum,courseType,section,courseID,courseTimes);
    return pointer;
}

std::vector<Course> CourseScanner::scanCourses(const std::string& input){
    auto matches = scanCourseStrings(input);
    std::vector<Course> courses;
    std::for_each(matches.begin(),matches.end(),[&courses](auto x){
        auto coursePtr = smatchToCourse(x);
        courses.push_back(*coursePtr);
    });
    return courses;
}
