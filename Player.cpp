#include "Player.h"
#include <random>
int Player::RandomNumber(int a, int b) {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(rd);
}
void Player::operator+(const Player &player) {
    _killed_enemies+=player._killed_enemies;
}
void Player::operator++() {
    _killed_enemies+=1000;
}
std::ostream &operator<<(std::ostream &os, const Player &player){
    os << "\n This player have killed: " << player._killed_enemies << "enemies";
    return os;
}
Player::Player()
: Player{"Frank", "emptyemail@gmail.com", RandomNumber(0,1000)}{}

Player::Player(const std::string &name)
: Player{name,"emptyemail@gmail.com", RandomNumber(0,1000)}{}

Player::Player(const std::string &name, const std::string &email)
: Player{name, email, RandomNumber(0,1000)}{}

Player::Player(const std::string &name, const std::string &email, int id)
:_name{name},_email{email}, _id{id}, purchased_upgrades{{}}{}

Player::~Player(){}