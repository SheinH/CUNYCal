//
// Created by Shein Htike on 2019-03-12.
//
#include <iostream>
#include <string>
#include <fstream>
#include <streambuf>
#include <regex>
#include "ScheduleRegex.h"

std::string get_file_contents(const char *filename)
{
	std::ifstream in(filename, std::ios::in | std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

int main(){
	std::string str = get_file_contents("ExampleSchedules/bryan.txt");

	std::cout << str << '\n';
	auto vect(CourseScanner::scanCourses(str));

	std::for_each(vect.begin(), vect.end(),[](auto course){
		std::cout << course << std::endl << std::endl;
	});
}