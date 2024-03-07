#include "Enemy.h"
Enemy::Enemy()
: Enemy{1}{}

Enemy::Enemy(int hp)
:_hp{hp}{}

Enemy &Enemy::operator=(const Enemy &rhs) {
    if(this != &rhs){
        _hp = rhs._hp;
    }
    return *this;
}
Enemy::~Enemy() {}