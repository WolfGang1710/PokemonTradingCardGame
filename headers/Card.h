//
// Created by ecole on 05/01/2024.
//

#ifndef POKEMONTRADINGCARDGAME_CARD_H
#define POKEMONTRADINGCARDGAME_CARD_H
#include <iostream>
#include <string>
using namespace std;

class Card {
protected:
    string cardName;
public:
    Card(const string& cardName);
    virtual ~Card() = default;

    virtual void displayInfo() const = 0;

    const string &getCardName() const;
};


#endif //POKEMONTRADINGCARDGAME_CARD_H
