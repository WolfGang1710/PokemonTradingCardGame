//
// Created by ecole on 05/01/2024.
//

#include "headers/EnergyCard.h"

EnergyCard::EnergyCard(const string &_energyType):
Card("Energy"), energyType(_energyType)
{}

void EnergyCard::displayInfo() const {
    cout << endl << "Card name: ";
    Card::displayInfo();
    cout << endl << "Energy type: " << energyType;
}

const string &EnergyCard::getEnergyType() const {
    return energyType;
}
