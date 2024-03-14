#ifndef CLICKER_MOB_H
#define CLICKER_MOB_H
#include <iostream>
#include "Enemy.h"

class Mob: public Enemy{
private:
    int _hp;
public:
    virtual void show_info() const override;
    virtual void take_damage(int damage) override;
    Mob();
    Mob(int hp);
    Mob(Mob &&other) noexcept;
    Mob(const Mob &other);
    Mob &operator=(const Mob &rhs);
    virtual ~Mob();
};


#endif
