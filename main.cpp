#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <memory>
#include "Player.h"
#include "Upgrade.h"
#include "Enemy.h"
#include "Mob.h"
#include "Weapon.h"

#define start_button_code '1'
#define stats_button_code '2'
#define blacksmith_button_code '3'
#define achievement_button_code '4'
#define leaderboard_button_code '5'
#define escape_button_code '6'

namespace fs = std::filesystem;

void admin_login(std::string &command) {
    std::cout << "Who You want to change?" << std::endl;
    getline(std::cin, command);
    Player temp_player;
    std::ofstream temp_ofs;

    for (const auto &file: fs::directory_iterator("Users")) {
        if (command == file.path().filename().string()) {
            Player::download_info_about_player(temp_player, file.path().string(), command);
        }
    }
    while (command != "exit") {
        system("clear");
        std::cout << "Okay. What you want to do?" << std::endl;
        getline(std::cin, command);
        if (command == "kills") {
            std::cout << "Current kills of " << temp_player.get_name()
                      << " is " << temp_player.get_kills() << std::endl
                      << "Enter new amount, please:";
            getline(std::cin, command);
            temp_player.set_new_score(std::stoi(command));
            temp_ofs.open("admin_log", std::ostream::app);
            temp_ofs << "Changed " << temp_player.get_name() << "`s score of kills to "
                     << command << std::endl;
            temp_ofs.close();
        } else if (command == "email") {
            std::cout << "Current email of" << temp_player.get_name()
                      << " is " << temp_player.get_email() << std::endl
                      << "Enter new email, please:";
            getline(std::cin, command);
            temp_player.set_new_email(command);
            temp_ofs.open("admin_log", std::ostream::app);
            temp_ofs << "Changed " << temp_player.get_name() << "`s email to " << command << std::endl;
            temp_ofs.close();
        } else if (command == "id") {
            std::cout << "Current id of" << temp_player.get_name()
                      << " is " << temp_player.get_id() << std::endl
                      << "Enter new id, please:";
            getline(std::cin, command);
            temp_player.set_new_id(std::stoi(command));
            temp_ofs.open("admin_log", std::ostream::app);
            temp_ofs << "Changed " << temp_player.get_name() << "`s id to " << command << std::endl;
            temp_ofs.close();
        } else if (command == "name") {
            std::cout << "Enter new name please:";
            getline(std::cin, command);
            std::string temp_name = temp_player.get_name();
            temp_player.set_new_name(command);
            fs::remove("Users/" + temp_name + ".txt");
            temp_ofs.open("admin_log", std::ostream::app);
            temp_ofs << "Changed " << temp_name << "`s name to " << command << std::endl;
            temp_ofs.close();
        }
    }
    Player::upload_info_about_player(temp_player, "Users/" + temp_player.get_name());
}

void display_enemy_alive() {
    std::cout << R"(     \\\|||///)" << std::endl
              << "   .  ======= " << std::endl
              << R"(  / \| O   O |)" << std::endl
              << R"(  \ / \`___'/ )" << std::endl
              << "   #   _| |_" << std::endl
              << "  (#) (     )" << std::endl
              << R"(   #\//|* *|\\)" << std::endl
              << R"(   #\/(  *  )/)" << std::endl
              << "   #   =====  " << std::endl
              << "   #   ( U ) " << std::endl
              << "   #   || ||" << std::endl
              << "  .#---'| |`----." << std::endl
              << "  `#----' `-----'" << std::endl;
}

void display_enemy_dead() {
    std::cout << R"(     \\\|||///)" << std::endl
              << "   .  ======= " << std::endl
              << R"(  / \| X   X |)" << std::endl
              << R"(  \ / \`___'/ )" << std::endl
              << "   #   _| |_" << std::endl
              << "  (#) (     )" << std::endl
              << R"(   #\//|* *|\\)" << std::endl
              << R"(   #\/(  *  )/)" << std::endl
              << "   #   =====  " << std::endl
              << "   #   ( U ) " << std::endl
              << "   #   || ||" << std::endl
              << "  .#---'| |`----." << std::endl
              << "  `#----' `-----'" << std::endl;
}

void start_button(Player &player) {
    system("clear");
    std::unique_ptr<Mob> current_enemy = std::make_unique<Mob>(player.get_kills() + 1);
    while (!GetAsyncKeyState(escape_button_code)) {
        system("clear");
        std::cout << "|  Kill the inviders to earn money and free your land  |" << std::endl;
        std::cout << "| Current enemy HP:" << current_enemy->get_hp() << " |" << std::endl;
        display_enemy_alive();
        std::cout << "| Current balance:" << player.get_balance() << " |" << std::endl;
        std::cout << "|6|     Exit     |6|" << std::endl;
        while (true) {
            if (GetAsyncKeyState(' ')) {
                current_enemy->take_damage(player.get_weapon().get_damage());
                if (current_enemy->get_hp() <= 0) {
                    system("clear");
                    std::cout << "|  Kill the inviders to earn money and free your land  |" << std::endl;
                    std::cout << "| Current enemy HP:" << current_enemy->get_hp() << " |" << std::endl;
                    display_enemy_dead();
                    std::cout << "| Current balance:" << player.get_balance() << " |" << std::endl;
                    std::cout << "|6|     Exit     |6|" << std::endl;
                    Sleep(1000);
                    player++;
                    player.update_balance(current_enemy->get_reward());
                    current_enemy = std::make_unique<Mob>(player.get_kills() + 1);
                }
                break;
            } else if (GetAsyncKeyState(escape_button_code)) {
                Sleep(200);
                return;
            }
        }
    }
}

void stats_button(Player &player) {
    system("clear");
    std::cout << "Hi, " << player.get_name() << "!" << std::endl
    << "There you can find your something about your`s account" << std::endl
    << "Killed enemies: " << player.get_kills() << std::endl
    << "Current balance:" << player.get_balance() << std::endl
    << "Your weapon is " << player.get_weapon().get_name()
    << " with " << player.get_weapon().get_damage() << " damage per click"
    << " at level " << player.get_weapon().get_level() << std::endl
    << "|6|     Exit     |6|" << std::endl;
    while (true)
    {
        if(GetAsyncKeyState(escape_button_code))
        {
            Sleep(100);
            break;
        }
    }
}
void leaderboard_button(Player &player)
{}

void blacksmith_button(Player &player) {}

void achievements_button(Player &player) {}

void open_player_main_menu(Player &player) {
    while (true) {
        system("clear");
        std::cout << "|1|    Start     |1|" << std::endl;
        std::cout << "|2|    Stats     |2|" << std::endl;
        std::cout << "|3|  Blacksmith  |3|" << std::endl;
        std::cout << "|4| Achievements |4|" << std::endl;
        std::cout << "|5|   Leaders    |5|" << std::endl;
        std::cout << "|6|     Exit     |6|" << std::endl;
        while (true) {
            if (GetAsyncKeyState(start_button_code)) {
                start_button(player);
                break;
            } else if (GetAsyncKeyState(stats_button_code)) {
                stats_button(player);
                break;
            }
            else if (GetAsyncKeyState(blacksmith_button_code)) blacksmith_button(player);
            else if (GetAsyncKeyState(achievement_button_code)) achievements_button(player);
            else if (GetAsyncKeyState(leaderboard_button_code)) leaderboard_button(player);
            else if (GetAsyncKeyState(escape_button_code)) {
                system("clear");
                Player::upload_info_about_player(player, "Users/" + player.get_name());
                return;
            }
            Sleep(100);
        }
    }
}


void player_login(std::string &command, Player &player) {
    open_player_main_menu(player);
}

void set_password(const std::string &password_to_set) {
    std::ofstream password("password", std::ofstream::out);
    password << password_to_set;
    password.close();
}

int main() {
    system("clear");
    set_password("8246");
    std::string command;
    Player player;
    fs::create_directory("Users");
    std::cout << "Hi! Can I know your name before we get started?" << std::endl;
    getline(std::cin, command);
    if (command == "admin") {
        std::cout << "Please, enter the password:";
        getline(std::cin, command);
        std::ifstream check_password("password", std::ifstream::out);
        std::string temp_password;
        getline(check_password, temp_password);
        if (command == temp_password) {
            admin_login(command);
            return 0;
        } else {
            int number_of_tries = 2;
            while (number_of_tries != 0) {
                std::cout << "Please, try again" << std::endl;
                getline(std::cin, command);
                number_of_tries--;
                system("clear");
                if (command == temp_password) {
                    admin_login(command);
                    return 0;
                }
            }
            std::cout << "You are not him. Press enter to exit and don`t bother me again";
            return 0;
        }
    } else {
        for (const auto &file: fs::directory_iterator("Users")) {
            if (command == file.path().filename().string()) {
                Player::download_info_about_player(player, file.path().string(), command);
                std::cout << "Hi, " << command << "! It`s nice to see you again!"
                          << "Press Enter to start" << std::endl;
                getline(std::cin, command);
                player_login(command, player);
                return 0;
            }
        }
        std::cout << "Sorry but I don`t know you yet. Wanna create account?" << std::endl;
        getline(std::cin, command);
        if (command == "yes") {
            std::cout << "Sorry, what`s your name again?" << std::endl;
            getline(std::cin, command);
            Player temp_player(command);
            fs::create_directory("Users/" + command);
            Player::upload_info_about_player(temp_player, "Users/" + command);
            std::cout << "Okay, " << command << ", let the journey begin!" << std::endl;
            player_login(command, temp_player);
            return 0;
        } else return 0;
    }
}
