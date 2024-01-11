//
// Created by ecole on 05/01/2024.
//

#ifndef POKEMONTRADINGCARDGAME_ENERGYCARD_H
#define POKEMONTRADINGCARDGAME_ENERGYCARD_H

#include "Card.h"
#include <string>

using namespace std;


class EnergyCard : public Card{
private:
    string energyType;
public:
    EnergyCard(const string& energyType);
    void displayInfo() const override;
    virtual ~EnergyCard() = default;

    const string &getEnergyType() const;
};


#endif //POKEMONTRADINGCARDGAME_ENERGYCARD_H
