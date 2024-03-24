#include "Enemy.h"

void Enemy::show_info() const {
    std::cout << "Type of enemy is:" << this->_type << std::endl;
}

void Enemy::take_damage(int damage) {}

Enemy::Enemy()
        : Enemy{"common"} {}

Enemy::Enemy(const std::string &type)
        : _type{type} {}

Enemy &Enemy::operator=(const Enemy &rhs) {
    if (this != &rhs) {
        _type = rhs._type;
    }
    return *this;
}

Enemy::Enemy(Enemy &&other) noexcept
        : _type{other._type} {}

Enemy::Enemy(const Enemy &other)
        : _type{other._type} {}

Enemy::~Enemy() {}