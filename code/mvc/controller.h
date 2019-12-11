#ifndef _CONTROLLER_H_
#define _CONTROLLER_H_

// #include "command.h"
#include <iostream>
#include <string>

class Command;
class HitCommand;
class StandCommand;

class Controller {
public:
    virtual Command * handleInput()=0;
};

class TextController : public Controller {
public:
    Command * handleInput() {
        std::string s;
        std::cin >> s;
        if (s == "hit") return new HitCommand;
        else return new StandCommand;
    }
};

class LiveDangerously : public Controller {
public:
    Command * handleInput() {
        return new HitCommand;
    }
};

#endif