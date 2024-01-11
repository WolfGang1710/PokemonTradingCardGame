//
// Created by ecole on 05/01/2024.
//

#include "headers/TrainerCard.h"

TrainerCard::TrainerCard(const string& _trainerName, const string& _trainerEffect):
Card(_trainerName), trainerEffect(_trainerEffect)
{
}

void TrainerCard::displayInfo() const {
    cout << endl << "Trainer Card: ";
    Card::displayInfo(); // Affiche le nom du dresseur Pokémon
    cout << "Trainer Effect: " << trainerEffect << endl;
}

void TrainerCard::applyTrainerEffect() const {
    if(trainerEffect == "heal all your action Pokemon") {
        cout << endl << "Your Pokémon's energy is at its peak again!";
        // code
    } else {
        throw invalid_argument("Invalid trainer effect: " + trainerEffect);
    }
}

const string &TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}
