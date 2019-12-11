#ifndef _COMMAND_H_
#define _COMMAND_H_

// #include "model.h"
class Model;

class Command {
public:
    virtual void execute(Model *)=0;
};

class HitCommand : public Command {
public:
    void execute(Model *m);
};

class StandCommand : public Command {
public:
    void execute(Model *m);
};

#endif
