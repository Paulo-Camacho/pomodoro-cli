#include "Timer.h"
#include "Session.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Session session("Physics", 1);
    Timer start(session.getDuration());
    start.logic();
    return 0;
}
