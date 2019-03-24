//
// Created by Shein Htike on 2019-03-14.
//

#ifndef CUNYCLASSES_COURSE_H
#define CUNYCLASSES_COURSE_H
#include <string>
#include <vector>
#include <array>
#include <ostream>
#include <optional>

class Course {
public:

    struct Time {
        Time() = default;

        Time(unsigned int hour, unsigned int minute);

        unsigned int hour;
        unsigned int minute;

        friend std::ostream &operator<<(std::ostream &os, const Time &time1);
    };

    struct Meeting {
        Meeting();

        std::array<bool, 7> weekday;
        Time start;
        Time end;
        std::string building;
        std::string room;

        friend std::ostream &operator<<(std::ostream &os, const Meeting &meeting);
    };

    Course(const std::string &department, const unsigned int courseNum, const std::string &type,
           const std::string &section, const std::string &courseID, const std::vector<Meeting> &meetings);

    Course(const std::string &department, const unsigned int courseNum, const std::vector<Meeting> &meetings,
           const std::optional<std::string> &type,
           const std::optional<std::string> &section, const std::optional<std::string> &courseID
    );

private:
    const std::string department;
    const unsigned int courseNum;
    const std::optional<std::string> type;
    const std::optional<std::string> section;
    const std::optional<std::string> courseID;
    const std::vector<Meeting> meetings;
};


#endif //CUNYCLASSES_COURSE_H
