#ifndef CLICKER_MOB_H
#define CLICKER_MOB_H

#include <iostream>
#include "Enemy.h"

class Mob : public Enemy {
private:
    int _hp;
    int _money_for_kill;
public:
    virtual void show_info() const override;

    virtual void take_damage(int damage) override;

    int get_hp() const;

    int get_reward() const;

    Mob();

    Mob(int hp);

    Mob(int hp, int money);

    Mob(Mob &&other) noexcept;

    Mob(const Mob &other);

    Mob &operator=(const Mob &rhs);

    virtual ~Mob();
};


#endif
