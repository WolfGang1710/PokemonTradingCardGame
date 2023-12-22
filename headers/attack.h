//
// Created by ecole on 22/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_ATTACK_H
#define POKEMONTRADINGCARDGAME_ATTACK_H

#include <string>

using namespace std;

struct Attack {
    /**
     * @brief The name of the attack
     * @details The name of the attack
     */
    int energyCost;
    int actualEnergyCost;
    string description;
    int damage;
};

#endif //POKEMONTRADINGCARDGAME_ATTACK_H
