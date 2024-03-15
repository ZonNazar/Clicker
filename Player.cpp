#include "Player.h"
#include <random>
int Player::RandomNumber(int a, int b) {
    std::random_device rd;
    std::uniform_int_distribution<int> distribution(a,b);
    return distribution(rd);
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
void Player::show_info() const {
    std::cout << "Current score:" << _killed_enemies << std::endl;
}
void Player::operator+(const Player &player) {
    _killed_enemies+=player._killed_enemies;
}
int Player::operator++(int) {
    _killed_enemies+=1;
}
std::ostream &operator<<(std::ostream &os, const Player &player){
    os << "\n This player have killed: " << player._killed_enemies << "enemies";
    return os;
}

void Player::upload_info_about_player(const Player &player, std::ofstream &ofs, const std::string &path) {
    ofs.open(path+"/"+player._name+".txt", std::ofstream::out);
    ofs << player._name << std::endl
    << player._email << std::endl
    << player._id << std::endl
    << player._killed_enemies;
    ofs.close();
}

void Player::download_info_about_player(Player &player, std::ifstream &ifs, const std::string &path) {
    ifs.open(path,std::iostream::out);
    std::string currentLine;
    getline(ifs,currentLine);
    player.set_new_name(currentLine);
    getline(ifs,currentLine);
    player.set_new_email(currentLine);
    getline(ifs,currentLine);
    player.set_new_id(std::stoi(currentLine));
    getline(ifs,currentLine);
    player.set_new_score(std::stoi(currentLine));
    ifs.close();
}
Player::Player()
: Player{"Frank", "emptyemail@gmail.com", RandomNumber(0,1000)}{}

Player::Player(const std::string &name)
: Player{name,"emptyemail@gmail.com", RandomNumber(0,1000)}{}

Player::Player(const std::string &name, const std::string &email)
: Player{name, email, RandomNumber(0,1000)}{}

Player::Player(const std::string &name, const std::string &email, int id)
:_name{name},_email{email}, _id{id}, _killed_enemies{0}{}

Player::~Player(){}