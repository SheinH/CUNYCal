//
// Created by Shein Htike on 2019-03-12.
//
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include "ScheduleRegex.h"

int main(){
	std::ifstream t("ExampleSchedules/bryan.txt");
	std::string str;

	t.seekg(0, std::ios::end);
	str.reserve(t.tellg());
	t.seekg(0, std::ios::beg);

	str.assign((std::istreambuf_iterator<char>(t)),
			   std::istreambuf_iterator<char>());
	std::vector<std::string> array(CourseScanner::scanCourseStrings(str));
}