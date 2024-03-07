#include "Upgrade.h"

std::vector<Upgrade> Upgrade::bought_upgrades = {};


Upgrade Upgrade::find_by_name(const std::string &name){}


Upgrade::Upgrade()
: Upgrade{"Noname", "empty"} {}

Upgrade::Upgrade(const std::string &name)
:Upgrade{name, "empty"} {}

Upgrade::Upgrade(const std::string &name, const std::string &description)
:_name{name}, _description{description}{
    bought_upgrades.emplace_back(*this);
}

Upgrade::Upgrade(Upgrade &&other) noexcept
: _name{other._name}, _description{other._description}{
    bought_upgrades.emplace_back(*this);
}

Upgrade::Upgrade(const Upgrade &other)
:_name{other._name}, _description{other._description}{
    bought_upgrades.emplace_back(*this);
}