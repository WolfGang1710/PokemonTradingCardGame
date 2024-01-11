//
// Created by ecole on 05/01/2024.
//

#include "headers/EnergyCard.h"

EnergyCard::EnergyCard(const string &_energyType):
Card("Energy"), energyType(_energyType)
        /**
         * @brief: Constructor for EnergyCard
         * @details: Creates an EnergyCard with the given energyType. By default, the name of the card is "Energy" and cannot be changed.
         * @param: `_energyType`: string
         * @return: None
         */
{}

void EnergyCard::displayInfo() const {
    /**
     * @brief: Displays the information of the EnergyCard
     * @details: Displays the information of the EnergyCard, including the name of the card and the energy type.
     * @param: None
     * @return: None
     */
    cout << endl << "Card name: ";
    Card::displayInfo();
    cout << endl << "Energy type: " << energyType;
}

const string &EnergyCard::getEnergyType() const {
    /**
     * @brief: Returns the energy type of the EnergyCard
     * @param: None
     * @return: energyType: string
     */
    return energyType;
}
