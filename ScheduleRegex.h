//
// Created by Shein Htike on 2019-03-12.
//

#ifndef CUNYCLASSES_SCHEDULEREGEX_H
#define CUNYCLASSES_SCHEDULEREGEX_H

#include <string>
#include <vector>
#include <regex>
#include <array>

#define CLASS_REGEX_PATTERN "([A-Z]{2,5}) (\\d{5})-(\\w+)\\n(\\w+) \\((\\d+)\\)\\n((?:(?:[A-Z][a-z])+ \\d{1,2}:\\d{2}(?:(?:AM)|(?:PM)) - \\d{1,2}:\\d{2}(?:(?:AM)|(?:PM))\\n(?:\\S+ )+(?:\\S+)\\n{0,1})+)"



class Course {
public:
	struct Time{
		unsigned int hour;
		unsigned int minute;
	};

	struct TimeInterval{
		TimeInterval();
		std::array<bool,7> weekday;
		Time start;
		Time end;
	};
	Course(const std::string &department, unsigned int courseNum, const std::string &section);
	const std::string &getDepartment() const;
	unsigned int getCourseNum() const;
	const std::string &getSection() const;
	const std::vector<TimeInterval> &getTimeIntervals() const;

private:
	const std::string department;
	const unsigned int courseNum;
	const std::string section;
	const std::vector<TimeInterval> timeIntervals;
};

namespace CourseScanner{
	auto scanCourseStrings(const std::string& input){
		std::regex pattern(CLASS_REGEX_PATTERN);
		std::smatch matches;
		std::sregex_iterator iterator{input.begin(),input.end(),pattern};
		const std::sregex_iterator end;
		std::vector<std::string> courseStrings{7};
		while(iterator != end) {
			courseStrings.emplace_back(*iterator);
			iterator++;
		}
		return courseStrings;
	}
}

#endif //CUNYCLASSES_SCHEDULEREGEX_H
