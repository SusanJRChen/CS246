#ifndef _VIEW_H_
#define _VIEW_H_

#include "info.h"
#include <iostream>

class View {
public:
    virtual void notify(const Info &)=0;
};

class TextView : public View {
public:
    void notify(const Info & i) {
        if (i.player == -1) {
            std::cout << "Dealer gets ";
        }
        else {
            std::cout << "Player gets ";
        }
        std::cout << i.card << " (Total: " << i.total << ")" << std::endl;
        if (i.total > 21) std::cout << "Bust!" << std::endl;
    }
};

#endif