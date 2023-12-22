//
// Created by ecole on 22/12/2023.
//

#include "headers/EnergyCard.h"

string EnergyCard::getCardName() const{
    return cardName;
}

string EnergyCard::getEnergyType() const {
    return energyType;
}

EnergyCard::EnergyCard(const string _energyType):
energyType(_energyType)
{
}


