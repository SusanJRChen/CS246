#include "command.h"
#include "model.h"

void HitCommand::execute(Model *m) {
    m->hit();
}

void StandCommand::execute(Model *m) {
    m->stand();
}
