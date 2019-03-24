//
// Created by Shein Htike on 2019-03-14.
//

#include "Course.h"

Course::Course(const std::string &department, const unsigned int courseNum, const std::string &type,
               const std::string &section, const std::string &courseID, const std::vector<Course::Meeting> &meetings)
        : department(department), courseNum(courseNum), type(type), section(section), courseID(courseID),
          meetings(meetings) {}

Course::Meeting::Meeting() {
    std::fill(weekday.begin(), weekday.end(), false);
}

std::ostream &operator<<(std::ostream &os, const Course::Meeting &meeting) {
    os << "Days: ";
    for (int i = 0; i < 7; i++) {
        if (meeting.weekday[i])
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


Course::Course(const std::string &department, const unsigned int courseNum,
               const std::vector<Course::Meeting> &meetings, const std::optional<std::string> &type = std::nullopt,
               const std::optional<std::string> &section = std::nullopt,
               const std::optional<std::string> &courseID = std::nullopt) : department(department),
                                                                            courseNum(courseNum), type(type),
                                                                            section(section), courseID(courseID),
                                                                            meetings(meetings) {}
