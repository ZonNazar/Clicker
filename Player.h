#ifndef CLICKER_PLAYER_H
#define CLICKER_PLAYER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "Weapon.h"
#include "Description.h"

class Player : public Description {
private:
    int _killed_enemies;
    std::string _name;
    std::string _email;
    int _id;
    int _balance;
    Weapon _weapon;
public:
    Player();

    Player(const std::string &name);

    Player(const std::string &name, const std::string &email);

    Player(const std::string &name, const std::string &email, int id);

    Player(const std::string &name, const std::string &email, int id, int balance);

    Player(const Player &other);

    Player(Player &&other) noexcept;

    ~Player();

    int get_balance() const;

    int get_kills() const;

    std::string get_name() const;

    std::string get_email() const;

    int get_id() const;

    Weapon get_weapon() const;

    void set_new_name(const std::string &new_name);

    void set_new_email(const std::string &new_email);

    void set_new_id(int new_id);

    void set_new_score(int new_score);

    void set_new_weapon(Weapon &weapon);

    void set_new_balance(int new_balance);

    void update_balance(int money_to_add);

    void operator+(const Player &player);

    int operator++(int);

    Player &operator=(const Player &other);

    virtual void show_info() const override;

    static void upload_info_about_player(const Player &player, const std::string &path);

    static void download_info_about_player(Player &player, const std::string &path, const std::string &name_to_find);

    static int RandomNumber(int a, int b);

    friend std::ostream &operator<<(std::ostream &os, const Player &player);
};


#endif
