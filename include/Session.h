#ifndef SESSION_HPP
#define SESSION_HPP
#include <string>

class Session
{
public:
    Session(const std::string& s, double d);
    const std::string& getSubject() const;
    double getDuration();

private:
    const std::string& subject;
    double duration;
};

#endif // SESSION_HPP
