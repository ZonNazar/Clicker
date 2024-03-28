#include "Player.h"
#include <random>
#include <fstream>

int Player::RandomNumber(int a, int b) {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(a, b);
    return distribution(rd);
}

int Player::get_kills() const {
    return _killed_enemies;
}

std::string Player::get_name() const {
    return _name;
}

std::string Player::get_email() const {
    return _email;
}

int Player::get_id() const {
    return _id;
}

int Player::get_balance() const {
    return _balance;
}

Weapon Player::get_weapon() const {
    return _weapon;
}

void Player::set_new_name(const std::string &new_name) {
    _name = new_name;
}

void Player::set_new_email(const std::string &new_email) {
    _email = new_email;
}

void Player::set_new_id(int new_id) {
    _id = new_id;
}

void Player::set_new_score(int new_score) {
    _killed_enemies = new_score;
}

void Player::set_new_balance(int new_balance) {
    _balance = new_balance;
}

void Player::set_new_weapon(Weapon &weapon) {
    _weapon = weapon;
}

void Player::update_balance(int money_to_add) {
    _balance += money_to_add;
}

void Player::show_info() const {
    std::cout << "Current score:" << _killed_enemies << std::endl;
}

void Player::operator+(const Player &player) {
    _killed_enemies += player._killed_enemies;
}

int Player::operator++(int) {
    _killed_enemies += 1;
    return _killed_enemies;
}

Player &Player::operator=(const Player &other) {
    if (this != &other) {
        _name = other._name;
        _email = other._email;
        _id = other._id;
        _balance = other._balance;
        _killed_enemies = other._killed_enemies;
        _weapon = other._weapon;
        return *this;
    } else return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &player) {
    os << "\n This player have killed: " << player._killed_enemies << "enemies";
    return os;
}

void Player::upload_info_about_player(const Player &player, const std::string &path) {
    std::ofstream ofs(path + "/" + player._name + ".txt", std::ofstream::out);
    ofs << player._name << std::endl
        << player._email << std::endl
        << player._id << std::endl
        << player._killed_enemies << std::endl
        << player._balance;
    ofs.close();
    Weapon::upload_info_about_weapon(player._weapon, path);
}

void Player::download_info_about_player(Player &player, const std::string &path, const std::string &name_to_find) {
    std::string file_to_find = path + name_to_find + ".txt";
    std::ifstream ifs(path + "/" + name_to_find + ".txt", std::ifstream::out);
    std::string current_line;
    getline(ifs, current_line);
    player.set_new_name(current_line);
    getline(ifs, current_line);
    player.set_new_email(current_line);
    getline(ifs, current_line);
    player.set_new_id(std::stoi(current_line));
    getline(ifs, current_line);
    player.set_new_score(std::stoi(current_line));
    getline(ifs, current_line);
    player.set_new_balance(std::stoi(current_line));
    ifs.close();
    Weapon::download_info_about_weapon(player._weapon, path);
}

Player::Player()
        : Player{"Frank", "emptyemail@gmail.com", RandomNumber(0, 1000), 0} {}

Player::Player(const std::string &name)
        : Player{name, "emptyemail@gmail.com", RandomNumber(0, 1000), 0} {}

Player::Player(const std::string &name, const std::string &email)
        : Player{name, email, RandomNumber(0, 1000), 0} {}

Player::Player(const std::string &name, const std::string &email, int id)
        : Player{name, email, id, 0} {}

Player::Player(const std::string &name, const std::string &email, int id, int balance)
        : _name{name}, _email{email}, _id{id}, _balance{balance}, _killed_enemies{0}, _weapon{"stick", 1, 1} {}

Player::Player(const Player &other) {
    _name = other._name;
    _email = other._email;
    _id = other._id;
    _balance = other._balance;
    _killed_enemies = other._killed_enemies;
    _weapon = other._weapon;
}

Player::Player(Player &&other) noexcept {
    _name = other._name;
    _email = other._email;
    _id = other._id;
    _balance = other._balance;
    _killed_enemies = other._killed_enemies;
    _weapon = other._weapon;
}

Player::~Player() {}