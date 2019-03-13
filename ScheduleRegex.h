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

class Course {

public:

    struct Time{
        Time() = default;

        Time(unsigned int hour, unsigned int minute);

        unsigned int hour;
        unsigned int minute;

        friend std::ostream &operator<<(std::ostream &os, const Time &time1);
    };

    struct Meeting{
        Meeting();

        std::array<bool,7> weekday;
        Time start;
        Time end;
        std::string building;
        std::string room;

        friend std::ostream &operator<<(std::ostream &os, const Meeting &meeting);
    };
    Course(const std::string &department, const unsigned int courseNum, const std::string &type,
           const std::string &section, const std::string &courseID, const std::vector<Meeting> &meetings);
    const std::string &getDepartment() const;
    unsigned int getCourseNum() const;
    const std::string &getSection() const;

    friend std::ostream &operator<<(std::ostream &os, const Course &course);

private:
    const std::string department;
    const unsigned int courseNum;
    const std::string type;
    const std::string section;
    const std::string courseID;
    const std::vector<Meeting> meetings;
};

namespace CourseScanner{
    const std::array<std::string,7> daysOfWeek = {"Su","Mo","Tu","We","Th","Fr","Sa"};
    //Returns a vector of string matches from an input string
    auto scanCourseStrings(const std::string& input);//Makes a unique pointer to a course::time object
    auto makeTime(const std::string& hour, const std::string& minute, const std::string& ampm);
    //Returns a vector of Course::Meeting's from input
    auto scanCourseTimes(const std::string& input);
    auto smatchToCourse(const std::smatch& match);
    std::vector<Course> scanCourses(const std::string& input);
    /*
     */
}

#endif //CUNYCLASSES_SCHEDULEREGEX_H
