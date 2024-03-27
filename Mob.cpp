#include "Mob.h"

void Mob::show_info() const {
    Enemy::show_info();
    std::cout << "Hp:" << this->_hp << std::endl;
}

void Mob::take_damage(int damage) {
    this->_hp -= damage;
}

int Mob::get_hp() const {
    return _hp;
}

int Mob::get_reward() const {
    return _money_for_kill;
}

Mob::Mob()
        : Mob{1} {}

Mob::Mob(int hp)
        : Mob{hp, 10} {}

Mob::Mob(int hp, int money)
        : Enemy{}, _hp{hp}, _money_for_kill{money} {}

Mob &Mob::operator=(const Mob &rhs) {
    if (this != &rhs) {
        Enemy::operator=(rhs);
        _hp = rhs._hp;
        _money_for_kill = rhs._money_for_kill;
    }
    return *this;
}

Mob::Mob(Mob &&other) noexcept
        : Enemy{other}, _hp{other._hp}, _money_for_kill{other._money_for_kill} {}

Mob::Mob(const Mob &other)
        : Enemy{other}, _hp{other._hp}, _money_for_kill{other._money_for_kill} {}

Mob::~Mob() {
}