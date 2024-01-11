//
// Created by ecole on 05/01/2024.
//

#ifndef POKEMONTRADINGCARDGAME_TRAINERCARD_H
#define POKEMONTRADINGCARDGAME_TRAINERCARD_H

#include "Card.h"
#include <iostream>


class TrainerCard : public Card {
private:
    string trainerEffect;
public:
    TrainerCard(const string& trainerName, const string& trainerEffect);
    void displayInfo() const override;
    virtual ~TrainerCard() = default;
    void applyTrainerEffect() const;

    const string &getTrainerEffect() const;
};


#endif //POKEMONTRADINGCARDGAME_TRAINERCARD_H
