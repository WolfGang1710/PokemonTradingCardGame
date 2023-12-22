//
// Created by ecole on 22/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_ENERGYCARD_H
#define POKEMONTRADINGCARDGAME_ENERGYCARD_H


#include "Card.h"

class EnergyCard : public Card{
    private:
    string cardName="Energy";
    string energyType;
public:
    EnergyCard(string energyType);
    string getCardName();
    string getEnergyType();
    void setEnergyType(string energyType);
    void setCardName(string cardName);
    void displayCard();
};


#endif //POKEMONTRADINGCARDGAME_ENERGYCARD_H
