#include "Player.h"
#include <random>
int RandomNumber(int a, int b)
{
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(rd);
}
Player::Player()
: Player{"Frank", "emptyemail@gmail.com", RandomNumber(0,1000)}{}

Player::Player(const std::string &name)
: Player{name,"emptyemail@gmail.com", RandomNumber(0,1000)}{}

Player::Player(const std::string &name, const std::string &email)
: Player{name, email, RandomNumber(0,1000)}{}

Player::Player(const std::string &name, const std::string &email, int id)
:_name{name},_email{email}, _id{id}{}

Player::~Player(){}