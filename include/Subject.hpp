#ifndef SUBJECT_HPP
#define SUBJECT_HPP

#include <string>

class Subject
{ 
public:

    Subject(const std::string& n, double d);

    // Getters and setters 
    const std::string& getName() const;
    double getDuration() const;

private:

    double m_duration;
    const std::string m_subjectName;


   };
#endif //SUBJECT_HPP
