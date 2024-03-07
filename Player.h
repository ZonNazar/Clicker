#ifndef CLICKER_PLAYER_H
#define CLICKER_PLAYER_H
#include <iostream>
class Player {
private:
    std::string _name;
    std::string _email;
    int _id;
public:
    int RandomNumber(int a, int b);
    Player();
    Player(const std::string &name);
    Player(const std::string &name, const std::string &email);
    Player(const std::string &name, const std::string &email, int id);
    ~Player();
};


#endif