#ifndef CLICKER_ENEMY_H
#define CLICKER_ENEMY_H

#include <iostream>
#include "Description.h"

class Enemy : public Description {
private:
    std::string _type;
public:
    virtual void show_info() const override;

    virtual void take_damage(int damage);

    Enemy &operator=(const Enemy &rhs);

    Enemy();

    Enemy(const std::string &type);

    Enemy(Enemy &&other) noexcept;

    Enemy(const Enemy &other);

    virtual ~Enemy();
};


#endif
