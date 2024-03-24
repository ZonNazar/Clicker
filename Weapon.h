#ifndef CLICKER_WEAPON_H
#define CLICKER_WEAPON_H

#include <iostream>

class Weapon {
private:
    std::string _name;
    int _level;
    int _damage;
public:
    Weapon();

    Weapon(const std::string &name);

    Weapon(const std::string &name, int level);

    Weapon(const std::string &name, int level, int damage);

    ~Weapon();
};


#endif
