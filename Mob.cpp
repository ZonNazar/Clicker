#include "Mob.h"
Mob::Mob()
: Mob{"common"}{}

Mob::Mob(const std::string &type)
: Enemy{}, _type{type}{
    std::cout << "debug";
}

Mob &Mob::operator=(const Mob &rhs) {
    if(this != &rhs)
    {
        Enemy::operator=(rhs);
        _type = rhs._type;
    }
    return *this;
}

Mob::Mob(Mob &&other) noexcept
: Enemy{other},_type{other._type}{}

Mob::Mob(const Mob &other)
: Enemy{other}, _type{other._type}{}

Mob::~Mob(){}