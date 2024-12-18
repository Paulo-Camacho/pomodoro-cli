#ifndef SESSION_H
#define SESSION_H
#include <string>

class Session
{
public:
    // Constructors
    Session(const std::string& s, double d);

    // Functions 
    const std::string& getSubject() const;
    double getDuration();

private:
    const std::string& subject;
    double duration{};
};

#endif // SESSION_H
