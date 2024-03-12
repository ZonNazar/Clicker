#ifndef CLICKER_MOB_H
#define CLICKER_MOB_H
#include <iostream>
#include "Enemy.h"

class Mob: public Enemy{
private:
    std::string _type;
public:
    Mob();
    Mob(const std::string &type);
    Mob(Mob &&other) noexcept;
    Mob(const Mob &other);
    Mob &operator=(const Mob &rhs);
    virtual ~Mob();
};


#endif
