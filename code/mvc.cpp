#include "mvc/command.h"
#include "mvc/controller.h"
#include "mvc/view.h"
#include "mvc/model.h"

int main() {
    std::vector<Controller*> c = {new TextController, new LiveDangerously};
    std::vector<View*> v = {new TextView};

    Model *m = new Model{c, v};
    
    while (!m->finished()) {
        Command *c = m->handleInput(); 
        c->execute(m);
        delete c;
    }


    for (auto x : c) delete x;
    for (auto x : v) delete x;
    delete m;
}
