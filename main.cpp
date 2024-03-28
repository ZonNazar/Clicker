#include <iostream>
#include <fstream>
#include <filesystem>
#include <windows.h>
#include <memory>
#include "Player.h"
#include "Mob.h"
#include "Weapon.h"

#define start_button_code '1'
#define stats_button_code '2'
#define blacksmith_button_code '3'
#define leaderboard_button_code '4'
#define escape_button_code '5'

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
            temp_ofs.open("admin_log", std::ofstream::app);
            temp_ofs << "Changed " << temp_player.get_name() << "`s score of kills to "
                     << command << std::endl;
            temp_ofs.close();
        } else if (command == "email") {
            std::cout << "Current email of" << temp_player.get_name()
                      << " is " << temp_player.get_email() << std::endl
                      << "Enter new email, please:";
            getline(std::cin, command);
            temp_player.set_new_email(command);
            temp_ofs.open("admin_log", std::ofstream::app);
            temp_ofs << "Changed " << temp_player.get_name() << "`s email to " << command << std::endl;
            temp_ofs.close();
        } else if (command == "id") {
            std::cout << "Current id of" << temp_player.get_name()
                      << " is " << temp_player.get_id() << std::endl
                      << "Enter new id, please:";
            getline(std::cin, command);
            temp_player.set_new_id(std::stoi(command));
            temp_ofs.open("admin_log", std::ofstream::app);
            temp_ofs << "Changed " << temp_player.get_name() << "`s id to " << command << std::endl;
            temp_ofs.close();
        } else if (command == "name") {
            std::cout << "Enter new name please:";
            getline(std::cin, command);
            std::string temp_name = temp_player.get_name();
            temp_player.set_new_name(command);
            fs::rename("Users/" + temp_name, "Users/" + temp_player.get_name());
            fs::remove("Users/" + temp_player.get_name() + "/" + temp_name + ".txt");
            temp_ofs.open("admin_log", std::ofstream::app);
            temp_ofs << "Changed " << temp_name << "`s name to " << command << std::endl;
            temp_ofs.close();
        } else if (command == "weapon") {
            std::cout << "Choose what state of weapon you want to change" << std::endl;
            getline(std::cin, command);
            if (command == "name") {
                std::string temp_weapon_name = temp_player.get_weapon().get_name();
                std::cout << "Current name of " << temp_player.get_name() << "`s weapon is "
                          << temp_player.get_weapon().get_name() << std::endl
                          << "Enter new name: ";
                getline(std::cin, command);
                Weapon temp_weapon = temp_player.get_weapon();
                temp_weapon.set_new_name(command);
                temp_player.set_new_weapon(temp_weapon);
                temp_ofs.open("admin_log", std::ofstream::app);
                temp_ofs << temp_player.get_name() << "`s weapon name changed from "
                         << temp_weapon_name << " to " << temp_player.get_weapon().get_name();
                temp_ofs.close();
            } else if (command == "level") {
                int temp_weapon_level = temp_player.get_weapon().get_level();
                int new_level;
                std::cout << "Current lvl of " << temp_player.get_name() << "`s weapon is "
                          << temp_player.get_weapon().get_level() << std::endl
                          << "Enter new lvl: ";
                std::cin >> new_level;
                Weapon temp_weapon = temp_player.get_weapon();
                temp_weapon.set_new_level(new_level);
                temp_player.set_new_weapon(temp_weapon);
                temp_ofs.open("admin_log", std::ofstream::app);
                temp_ofs << temp_player.get_name() << "`s weapon level changed from "
                         << temp_weapon_level << " to " << temp_player.get_weapon().get_level();
                temp_ofs.close();
            } else if (command == "damage") {
                int temp_weapon_damage = temp_player.get_weapon().get_damage();
                int new_damage;
                std::cout << "Current damage of " << temp_player.get_name() << "`s weapon is "
                          << temp_player.get_weapon().get_damage() << std::endl
                          << "Enter new damage: ";
                std::cin >> new_damage;
                Weapon temp_weapon = temp_player.get_weapon();
                temp_weapon.set_new_damage(new_damage);
                temp_player.set_new_weapon(temp_weapon);
                temp_ofs.open("admin_log", std::ofstream::app);
                temp_ofs << temp_player.get_name() << "`s weapon damage changed from "
                         << temp_weapon_damage << " to " << temp_player.get_weapon().get_damage();
                temp_ofs.close();
            }
        }
    }
    fs::create_directory("Users/" + temp_player.get_name());
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
        std::cout << "|5|     Exit     |5|" << std::endl;
        while (true) {
            if (GetAsyncKeyState(' ')) {
                Sleep(100);
                current_enemy->take_damage(player.get_weapon().get_damage());
                if (current_enemy->get_hp() <= 0) {
                    system("clear");
                    std::cout << "|  Kill the inviders to earn money and free your land  |" << std::endl;
                    std::cout << "| Current enemy HP:" << 0 << " |" << std::endl;
                    display_enemy_dead();
                    std::cout << "| Current balance:" << player.get_balance() << " |" << std::endl;
                    std::cout << "|5|     Exit     |5|" << std::endl;
                    Sleep(1000);
                    player++;
                    player.update_balance(current_enemy->get_reward());
                    current_enemy = std::make_unique<Mob>(player.get_kills() + 1, player.get_kills() * 10);
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
              << "|5|     Exit     |5|" << std::endl;
    while (true) {
        if (GetAsyncKeyState(escape_button_code)) {
            Sleep(100);
            break;
        }
    }
}

void leaderboard_button(Player &player) {
    system("clear");
    while (!GetAsyncKeyState(escape_button_code)) {
        std::vector<Player> temp_players;
        std::vector<Player> temp_players_to_show;
        Player temp_player;
        for (auto &f: fs::directory_iterator("Users")) {
            Player::download_info_about_player(temp_player,
                                               f.path().string() + "/",
                                               f.path().filename().string());
            temp_players.emplace_back(temp_player);
        }
        std::cout << "| There is a hall of the greatest players ever |" << std::endl
                  << "|1|     Kills     |1|" << std::endl
                  << "|2|    Balance    |2|" << std::endl
                  << "|3| Weapon damage |3|" << std::endl
                  << "|5|      Exit     |5|" << std::endl;
        while (true) {
            if (GetAsyncKeyState('1')) { //leaders by kills
                system("clear");
                Sleep(100);
                temp_players_to_show = temp_players;
                for (int i = 0; i < temp_players_to_show.size(); i++) {
                    for (int j = i + 1; j < temp_players_to_show.size(); j++) {
                        try {
                            if (temp_players_to_show[j].get_kills() > temp_players_to_show[i].get_kills()) {
                                std::swap(temp_players_to_show[i], temp_players_to_show[j]);
                            }
                        } catch (const std::out_of_range &ex) {
                            break;
                        }
                    }
                }
                for (int i = 0; i <= 10; i++) {
                    try {
                        if (i >= temp_players_to_show.size()) throw std::bad_alloc();
                        std::cout << i + 1 << "." << temp_players_to_show[i].get_name()
                                  << " with " << temp_players_to_show[i].get_kills() << " kills. " << std::endl;
                    } catch (const std::bad_alloc &e) { break; }
                }
                for (int i = 0; i < temp_players_to_show.size(); i++) {
                    if (player.get_name() == temp_players_to_show[i].get_name()) {
                        std::cout << "Your position in top is: " << i + 1 << std::endl;
                    }
                }
                std::cout << "|5|      Exit     |5|" << std::endl;
                while (!GetAsyncKeyState(escape_button_code)) {}
                system("clear");
                Sleep(100);
                break;
            } else if (GetAsyncKeyState('2')) { //leaders by balance
                system("clear");
                Sleep(100);
                temp_players_to_show = temp_players;
                for (int i = 0; i < temp_players_to_show.size(); i++) {
                    for (int j = i + 1; j < temp_players_to_show.size(); j++) {
                        try {
                            if (temp_players_to_show[j].get_balance() > temp_players_to_show[i].get_balance()) {
                                std::swap(temp_players_to_show[i], temp_players_to_show[j]);
                            }
                        } catch (const std::out_of_range &ex) {
                            break;
                        }
                    }
                }
                for (int i = 0; i <= 10; i++) {
                    try {
                        if (i >= temp_players_to_show.size()) throw std::bad_alloc();
                        std::cout << i + 1 << "." << temp_players_to_show[i].get_name()
                                  << " with " << temp_players_to_show[i].get_balance() << " on balance. " << std::endl;
                    } catch (const std::bad_alloc &e) { break; }
                }
                for (int i = 0; i < temp_players_to_show.size(); i++) {
                    if (player.get_name() == temp_players_to_show[i].get_name()) {
                        std::cout << "Your position in top is: " << i + 1 << std::endl;
                    }
                }
                std::cout << "|5|      Exit     |5|" << std::endl;
                while (!GetAsyncKeyState(escape_button_code)) {}
                system("clear");
                Sleep(100);
                break;
            } else if (GetAsyncKeyState('3')) { //leaders by weapon damage
                system("clear");
                Sleep(100);
                temp_players_to_show = temp_players;
                for (int i = 0; i < temp_players_to_show.size(); i++) {
                    for (int j = i + 1; j < temp_players_to_show.size(); j++) {
                        try {
                            if (temp_players_to_show[j].get_weapon().get_damage() >
                                temp_players_to_show[i].get_weapon().get_damage()) {
                                std::swap(temp_players_to_show[i], temp_players_to_show[j]);
                            }
                        } catch (const std::out_of_range &ex) {
                            break;
                        }
                    }
                }
                for (int i = 0; i <= 10; i++) {
                    try {
                        if (i >= temp_players_to_show.size()) throw std::bad_alloc();
                        std::cout << i + 1 << "." << temp_players_to_show[i].get_name()
                                  << " with " << temp_players_to_show[i].get_weapon().get_damage() << " damage. "
                                  << std::endl;
                    } catch (const std::bad_alloc &e) { break; }
                }
                for (int i = 0; i < temp_players_to_show.size(); i++) {
                    if (player.get_name() == temp_players_to_show[i].get_name()) {
                        std::cout << "Your position in top is: " << i + 1 << std::endl;
                    }
                }
                std::cout << "|5|      Exit     |5|" << std::endl;
                while (!GetAsyncKeyState(escape_button_code)) {}
                system("clear");
                Sleep(100);
                break;
            } else if (GetAsyncKeyState(escape_button_code)) {
                system("clear");
                return;
            }
            Sleep(100);
        }
    }
}

void blacksmith_button(Player &player) {
    while (true) {
        int weapon_level = player.get_weapon().get_level();
        system("clear");
        int success_chance = 100 - (weapon_level / 100);
        int price = weapon_level * player.get_kills();
        std::cout << "| Hello there! |" << std::endl
                  << "| Your current weapon level is " << weapon_level << " |" << std::endl
                  << "| Success chance is " << success_chance << "% |" << std::endl
                  << "| It will cost you only " << price << " |" << std::endl
                  << "|1| Lets do it! |1|" << std::endl
                  << "|5|   Go back   |5|" << std::endl;
        while (true) {
            if (GetAsyncKeyState('1')) {
                Sleep(100);
                system("clear");
                if (Player::RandomNumber(0, 100) <= success_chance && player.get_balance() >= price) {
                    Weapon weapon_to_update = player.get_weapon();
                    weapon_to_update++;
                    player.set_new_weapon(weapon_to_update);
                    player.update_balance(-price);
                    Player::upload_info_about_player(player, "Users/" + player.get_name());
                    std::cout << "Success!" << std::endl;
                    Sleep(1000);
                    break;
                } else {
                    system("clear");
                    std::cout << "Upgrade failed" << std::endl;
                    Sleep(1000);
                    break;
                }
            } else if (GetAsyncKeyState(escape_button_code)) {
                Sleep(100);
                return;
            }
        }
    }
}

void open_player_main_menu(Player &player) {
    while (true) {
        system("clear");
        Sleep(100);
        std::cout << "|1|    Start     |1|" << std::endl
                  << "|2|    Stats     |2|" << std::endl
                  << "|3|  Blacksmith  |3|" << std::endl
                  << "|4|   Leaders    |4|" << std::endl
                  << "|5|     Exit     |5|" << std::endl;
        while (true) {
            if (GetAsyncKeyState(start_button_code)) {
                start_button(player);
                Player::upload_info_about_player(player, "Users/" + player.get_name());
                break;
            } else if (GetAsyncKeyState(stats_button_code)) {
                stats_button(player);
                break;
            } else if (GetAsyncKeyState(blacksmith_button_code)) {
                blacksmith_button(player);
                break;
            } else if (GetAsyncKeyState(leaderboard_button_code)) {
                leaderboard_button(player);
                break;
            } else if (GetAsyncKeyState(escape_button_code)) {
                system("clear");
                Player::upload_info_about_player(player, "Users/" + player.get_name());
                return;
            }
            Sleep(100);
        }
    }
}

void player_login(Player &player) {
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
                player_login(player);
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
            player_login(temp_player);
            return 0;
        } else return 0;
    }
}
