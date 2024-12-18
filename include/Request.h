#ifndef REQUEST_H
#define REQUEST_H
#include "Session.h"

class Request
{
public:
    Request(Session i);
    void ask();
private:
    Session init;
    double q;
};

#endif // REQUEST_H
