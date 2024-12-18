#include "Session.h"

// THIS CLASS JUST HAS TWO RETURN METHODS!
Session::Session(const std::string& s, double d) : subject(s), duration(d) {}

const std::string& Session::getSubject() const
{
    return subject;
}

double Session::getDuration()
{
    return duration;
}
