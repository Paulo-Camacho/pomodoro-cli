#ifndef REQUEST_HPP
#define REQUEST_HPP
#include "Session.hpp"

class Request
{
public:
    Request(Session i);
    void ask();
private:
    Session init;
    double q;
};

#endif // REQUEST_HPP
