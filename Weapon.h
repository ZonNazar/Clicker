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

    void set_new_name(std::string &new_name);

    void set_new_damage(int new_damage);

    void set_new_level(int new_level);

    std::string get_name() const;

    int get_damage() const;

    int get_level() const;

    void update_damage(int damage_to_add);

    int operator++(int);

    static void upload_info_about_weapon(const Weapon &weapon, const std::string &path);

    static void download_info_about_weapon(Weapon &weapon, const std::string &path);
};


#endif
