//
// Created by Shein Htike on 2019-03-14.
//

#include "Course.h"
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

std::ostream &operator<<(std::ostream &os, const Course &course) {
    os << "Department: " << course.department << " courseNum: " << course.courseNum << " type: " << course.type
       << " section: " << course.section << " courseID: " << course.courseID << " meetings: ";
    for (auto m : course.meetings) {
        os << m << '\n';
    }
    return os;
}
