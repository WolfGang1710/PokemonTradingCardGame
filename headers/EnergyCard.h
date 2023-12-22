//
// Created by ecole on 22/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_ENERGYCARD_H
#define POKEMONTRADINGCARDGAME_ENERGYCARD_H


#include "Card.h"

class EnergyCard : public Card{
//protected:
//    string CardName="Energy";
private:
    string cardName="Energy";
    string energyType;
public:
    EnergyCard(const string energyType);

    string getCardName() const;
    string getEnergyType() const;
};


#endif //POKEMONTRADINGCARDGAME_ENERGYCARD_H
