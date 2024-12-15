#include "Subject.hpp"

Subject::Subject(const std::string& n, double d) : m_subjectName(n), m_duration(d) {}

const std::string& Subject::getName() const {
    return m_subjectName; // Return by const reference
}

double Subject::getDuration() const {
    return m_duration;
}
