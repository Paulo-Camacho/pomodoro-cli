#include "Session.hpp"

Session::Session(const std::string& s, double d) : subject(s), duration(d) {}

const std::string& Session::getSubject() const
{
    return subject;
}

double Session::getDuration()
{
    return duration;
}
