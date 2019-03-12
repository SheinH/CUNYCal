//
// Created by Shein Htike on 2019-03-12.
//

#ifndef CUNYCLASSES_SCHEDULEREGEX_H
#define CUNYCLASSES_SCHEDULEREGEX_H

#include <string>
#include <vector>
#include <ctime>
#include <regex>
#include <array>

#define CLASS_REGEX_PATTERN "(?<subject>[A-Z]{3,4}) (?<classcode>\\d{5})-(?<section>\\w{1,3})\\n.+\\n(?:(?<days>(?:[A-Z][a-z]){1,7}) \\d{1,2}:\\d\\d((AM)|(PM)) - \\d{1,2}:\\d\\d((AM)|(PM))\\n(\\S+ )+(\\S+)\\n{0,1})+"

struct TimeInterval{
	TimeInterval();

	std::array<bool,7> weekday;
	time_t beginning;
	time_t end;
};

class Course {
public:
	Course(const std::string &department, const unsigned int courseNum, const std::string &section);
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

Course& scanCourse(const std::string& input) {
	std::regex pattern(CLASS_REGEX_PATTERN);
	std::smatch matches;
	if(std::regex_search(input,matches,pattern))
		
}

#endif //CUNYCLASSES_SCHEDULEREGEX_H
