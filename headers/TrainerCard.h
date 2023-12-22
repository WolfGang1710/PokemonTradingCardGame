//
// Created by ecole on 22/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_TRAINERCARD_H
#define POKEMONTRADINGCARDGAME_TRAINERCARD_H


#include "Card.h"

class TrainerCard : public Card{
private:
    string cardName;
    string trainerEffect;
public:
    TrainerCard(string Trainer, string trainerEffect);
};


#endif //POKEMONTRADINGCARDGAME_TRAINERCARD_H
