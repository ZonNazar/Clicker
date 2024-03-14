#include "Mob.h"

void Mob::show_info() const {
Enemy::show_info();
std::cout << "Hp:" << this->_hp << std::endl;
}

void Mob::take_damage(int damage){
    this->_hp-=damage;
    if(this->_hp <= 0) Mob::~Mob();
}

Mob::Mob()
: Mob{1}{}

Mob::Mob(int hp)
: Enemy{}, _hp{hp}{}

Mob &Mob::operator=(const Mob &rhs) {
    if(this != &rhs)
    {
        Enemy::operator=(rhs);
        _hp = rhs._hp;
    }
    return *this;
}

Mob::Mob(Mob &&other) noexcept
: Enemy{other},_hp{other._hp}{}

Mob::Mob(const Mob &other)
: Enemy{other}, _hp{other._hp}{}

Mob::~Mob(){
    std::cout << "MD";
}