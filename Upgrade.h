#ifndef CLICKER_UPGRADE_H
#define CLICKER_UPGRADE_H
#include <iostream>
#include <vector>

class Upgrade {
public:
    static std::vector<Upgrade> bought_upgrades;
private:
    std::string _name;
    std::string _description;
public:
    static Upgrade find_by_name(const std::string &name);

    Upgrade();
    Upgrade(const std::string &name);
    Upgrade(const std::string &name, const std::string &description);
    Upgrade(const Upgrade &other);
    Upgrade(Upgrade &&other) noexcept;
    ~Upgrade();
};


#endif
