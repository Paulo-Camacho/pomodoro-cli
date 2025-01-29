#ifndef SUBJECT_HPP
#define SUBJECT_HPP
#include <string>

class Subject {
public:
    Subject();
    void displayQuestion();
    std::string getSubject() const; // ✅ Add this getter method
private:
    std::string subject;
};

#endif // SUBJECT_HPP
