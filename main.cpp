#include <iostream>
#include "Player.h"
#include "Upgrade.h"
#include "Enemy.h"
#include "Mob.h"
#include "Weapon.h"

int main() {
    std::string command;
    Player player;
    Enemy *enemy = new Mob("noth");

    delete enemy;

    int numOfClicks = 0;
    while(command != "exit"){
        getline(std::cin, command);
        if(command.empty()) numOfClicks++;
        system("clear");
        std::cout << "Number of clicks: "<< numOfClicks << std::endl;
    }
    return 0;
}
