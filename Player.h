#ifndef CLICKER_PLAYER_H
#define CLICKER_PLAYER_H
#include <iostream>
#include <vector>
#include "Upgrade.h"
#include "Weapon.h"
#include "Description.h"
class Player: public Description{
private:
    int _killed_enemies;
    std::string _name;
    std::string _email;
    int _id;
    Weapon currentWeapon;
    std::vector<Upgrade> purchased_upgrades;
public:
    virtual void show_info() const override;
    int RandomNumber(int a, int b);
    Player();
    Player(const std::string &name);
    Player(const std::string &name, const std::string &email);
    Player(const std::string &name, const std::string &email, int id);
    void operator+(const Player &player);
    void operator++();
    friend std::ostream &operator<<(std::ostream &os, const Player &player);
    ~Player();
};


#endif
