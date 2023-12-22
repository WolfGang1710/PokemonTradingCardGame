//
// Created by ecole on 22/12/2023.
//

#include "headers/TrainerCard.h"
#include "headers/Player.h"
#include <iostream>

TrainerCard::TrainerCard(const string trainerName, const string _trainerEffect) :
cardName(trainerName), trainerEffect(_trainerEffect)
{
}

string TrainerCard::getCardName() const {
    /**
     * @returns the name of the TrainerCard.
     */
    return cardName;
}

string TrainerCard::getTrainerEffect() const {
    /**
     * @params index: the index of the TrainerCard in the Player's bench.
     * @returns the effect of the TrainerCard.
     */
    return trainerEffect;
}
