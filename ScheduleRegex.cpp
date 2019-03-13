//
// Created by Shein Htike on 2019-03-12.
//

#include "ScheduleRegex.h"
#include <vector>

const std::string &Course::getDepartment() const {
	return department;
}

unsigned int Course::getCourseNum() const {
	return courseNum;
}

const std::string &Course::getSection() const {
	return section;
}

const std::vector<Course::TimeInterval> &Course::getTimeIntervals() const {
	return timeIntervals;
}

Course::Course(const std::string &department, const unsigned int courseNum, const std::string &section) : department(
		department), courseNum(courseNum), section(section) {}

Course::TimeInterval::TimeInterval() {
	std::fill(weekday.begin(),weekday.end(),false);
}