//
// Created by ecole on 05/01/2024.
//

#include "headers/Card.h"
#include <iostream>

using namespace std;

Card::Card(const string& _cardName):
        /**
         *  @brief: Constructor for the card object
         *  @param `_cardName`: the name of the card
         *  @return: none
         */
        cardName(_cardName)
{
}

void Card::displayInfo() const {
    /**
     *  @brief: Display the card's name
     *  @param: none
     *  @return: none
     */
    cout << endl << "Card name: " << cardName ;
}

const string &Card::getCardName() const {
    /**
     *  @brief: Get the card's name
     *  @param: none
     *  @return: the card's name
     */
    return cardName;
}


