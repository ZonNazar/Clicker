#include "Weapon.h"
#include <fstream>

void Weapon::set_new_name(std::string &new_name) {
    _name = new_name;
}
void Weapon::set_new_damage(int new_damage) {
    _damage = new_damage;
}
void Weapon::set_new_level(int new_level) {
    _level = new_level;
}
std::string Weapon::get_name() const {
    return _name;
}
int Weapon::get_damage() const {
    return _damage;
}
int Weapon::get_level() const {
    return _level;
}
void Weapon::download_info_about_weapon(Weapon &weapon, const std::string &path) {
    std::ifstream ifs(path+"/Weapon.txt", std::ifstream::out);
    std::string current_line;
    getline(ifs, current_line);
    weapon.set_new_name(current_line);
    getline(ifs,current_line);
    weapon.set_new_level(std::stoi(current_line));
    getline(ifs,current_line);
    weapon.set_new_damage(std::stoi(current_line));
    ifs.close();
}
void Weapon::upload_info_about_weapon(const Weapon &weapon, const std::string &path) {
    std::ofstream ofs(path+"/Weapon.txt", std::ofstream::out);
    ofs << weapon._name << std::endl
    << weapon._level << std::endl
    << weapon._damage;
    ofs.close();
}

void Weapon::update_damage(int damage_to_add) {
    _damage+=damage_to_add;
}

int Weapon::operator++(int) {
    _level++;
    update_damage(_level*2);
    return _level;
}

Weapon::Weapon()
        : Weapon{"Noname", 1, 1} {}

Weapon::Weapon(const std::string &name)
        : Weapon{name, 1, 1} {}

Weapon::Weapon(const std::string &name, int level)
        : Weapon{name, level, 1} {}

Weapon::Weapon(const std::string &name, int level, int damage)
        : _name{name}, _level{level}, _damage{damage} {}

Weapon::~Weapon() {}