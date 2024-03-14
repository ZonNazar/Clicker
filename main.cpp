#include <iostream>
#include <fstream>
#include <filesystem>
#include "Player.h"
#include "Upgrade.h"
#include "Enemy.h"
#include "Mob.h"
#include "Weapon.h"

namespace fs = std::filesystem;

int main() {
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
    }else{
        bool found_user = false;
        for(const auto &file : fs::directory_iterator("Users")){
            if(command+".txt" == file.path().filename().string()) {
                std::ifstream ifs;
                Player::download_info_about_player(player,ifs, file.path().string());
                std::cout << "Hi, " << command << "! It`s nice to see you again!"
                          << "Press Enter to start" << std::endl;
                getline(std::cin, command);
                found_user = true;
                break;
            }
        }
        if(!found_user) {
            std::cout << "Sorry but I don`t know you yet. Wanna create account?" << std::endl;
            getline(std::cin, command);
            if(command == "yes"){
                std::cout << "Sorry, what`s your name again?" << std::endl;
                getline(std::cin, command);
                Player temp_player(command);
                std::ofstream file_to_write;
                Player::upload_info_about_player(temp_player,file_to_write, "Users");
                std::cout << "Okay, " << command << ", let the journey begin!" << std::endl;
            } else return 0;
        }
    }
    while(command != "exit"){
        getline(std::cin, command);
        if(command.empty())
        system("clear");
    }
    return 0;
}
