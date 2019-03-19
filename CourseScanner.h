//
// Created by Shein Htike on 2019-03-12.
//

#ifndef CUNYCLASSES_SCHEDULEREGEX_H
#define CUNYCLASSES_SCHEDULEREGEX_H

#include <string>
#include <vector>
#include <regex>
#include <array>
#include <memory>
#include <ostream>
#include "Course.h"

class CourseScanner {
public:
	class Exception : public std::runtime_error {
	public:
		Exception(const std::string &);
	};

    static std::vector<Course> scanCourses(const std::string &input);

    static bool isValidCourseString(const std::string &input);
private:

    inline static const std::array<std::string, 7> daysOfWeek{"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};

	//Returns a vector of string matches from an input string
    static auto scanCourseStrings(const std::string &input);//Makes a unique pointer to a course::time object
    static auto makeTime(const std::string &hour, const std::string &minute, const std::string &ampm);

	//Returns a vector of Course::Meeting's from input
    static auto scanCourseTimes(const std::string::const_iterator &stringStart, const std::string::const_iterator &stringEnd);

    static auto smatchToCourse(const std::smatch &match);
	/*
	 */
};

#endif //CUNYCLASSES_SCHEDULEREGEX_H
