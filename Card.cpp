//
// Created by ecole on 05/01/2024.
//

#include "headers/Card.h"
#include <iostream>

using namespace std;

Card::Card(const string& _cardName):
        cardName(_cardName)
{
}

void Card::displayInfo() const {
    cout << endl << "Card name: " << cardName ;
}

const string &Card::getCardName() const {
    return cardName;
}


