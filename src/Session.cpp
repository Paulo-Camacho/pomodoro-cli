#include "Session.h"

Session::Session(const std::string& s, double d) : subject(s), duration(d) {}

// THIS CLASS JUST HAS TWO RETURN METHODS!
const std::string& Session::getSubject() const
{
    return subject;
}

double Session::getDuration()
{
    return duration;
}
