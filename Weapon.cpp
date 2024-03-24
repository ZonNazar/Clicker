#include "Weapon.h"

Weapon::Weapon()
        : Weapon{"Noname", 1, 1} {}

Weapon::Weapon(const std::string &name)
        : Weapon{name, 1, 1} {}

Weapon::Weapon(const std::string &name, int level)
        : Weapon{name, level, 1} {}

Weapon::Weapon(const std::string &name, int level, int damage)
        : _name{name}, _level{level}, _damage{damage} {}