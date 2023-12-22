//
// Created by ecole on 22/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_PLAYER_H
#define POKEMONTRADINGCARDGAME_PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"

using namespace std;

class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;

public:
    Player(string playerName);
    void addCardToBench(const Card*);
    void activatePokemonCard(const int);
    void attachEnergyCard(const int, const int);
    void displayBench();
    void displayAction();
    void attack(const int, const int, const Player, const int);
    void useTrainer();
};


#endif //POKEMONTRADINGCARDGAME_PLAYER_H
