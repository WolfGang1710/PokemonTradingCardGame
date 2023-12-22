//
// Created by ecole on 21/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_CARD_H
#define POKEMONTRADINGCARDGAME_CARD_H

#include <string>

using namespace std;

class Card {
private:
    string cardName;
public:
    virtual void displayInfo();
};


#endif //POKEMONTRADINGCARDGAME_CARD_H
