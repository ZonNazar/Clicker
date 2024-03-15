#include <iostream>
#include <fstream>
#include <filesystem>
#include "Player.h"
#include "Upgrade.h"
#include "Enemy.h"
#include "Mob.h"
#include "Weapon.h"

namespace fs = std::filesystem;
void admin_login(std::string &command)
{
    while(command != "exit"){
        getline(std::cin, command);
        if(command.empty())
            system("clear");
    }
}
void player_login(std::string &command, Player &player)
{
    while(command != "exit"){
        getline(std::cin, command);
        if(command.empty()) player++;
            system("clear");
    }
}
int main() {
    std::ofstream password("password", std::ofstream::out);
    password << "8246";
    password.close();
    system("clear");
    std::string command;
    Player player;
    try{
        fs::create_directory("Users");
    }catch(...){}
    std::cout << "Hi! Can I know your name before we get started?"<<std::endl;
    getline(std::cin, command);
    if(command == "admin")
    {
        std::cout << "Please, enter the password:";
        getline(std::cin, command);
        std::ifstream check_password("password", std::ifstream::out);
        std::string temp_password;
        getline(check_password, temp_password);
        if(command == temp_password){
            admin_login(command);
            return 0;
        }
        else{
            int number_of_tries = 2;
            while (number_of_tries != 0)
            {
                std::cout << "Please, try again" << std::endl;
                getline(std::cin, command);
                number_of_tries--;
                system("clear");
                if(command == temp_password){
                    admin_login(command);
                    return 0;
                }
            }
            std::cout << "You are not him. Press enter to exit and don`t bother me again";
            return 0;
        }
    }else{
        for(const auto &file : fs::directory_iterator("Users")){
            if(command+".txt" == file.path().filename().string()) {
                std::ifstream ifs;
                Player::download_info_about_player(player,ifs, file.path().string());
                std::cout << "Hi, " << command << "! It`s nice to see you again!"
                          << "Press Enter to start" << std::endl;
                getline(std::cin, command);
                player_login(command, player);
                return 0;
            }
        }
        std::cout << "Sorry but I don`t know you yet. Wanna create account?" << std::endl;
        getline(std::cin, command);
        if(command == "yes") {
            std::cout << "Sorry, what`s your name again?" << std::endl;
            getline(std::cin, command);
            Player temp_player(command);
            std::ofstream file_to_write;
            Player::upload_info_about_player(temp_player, file_to_write, "Users");
            std::cout << "Okay, " << command << ", let the journey begin!" << std::endl;
            player_login(command, temp_player);
            return 0;
        }else return 0;
    }
}
