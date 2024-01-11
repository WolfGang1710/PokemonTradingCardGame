//
// Created by ecole on 05/01/2024.
//

#ifndef POKEMONTRADINGCARDGAME_PLAYER_H
#define POKEMONTRADINGCARDGAME_PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "PokemonCard.h"
#include "TrainerCard.h"


class Player {
private:
    string playerName;
    vector<Card*> benchCards;
    vector<PokemonCard*> actionCards;
    vector<TrainerCard*> trainerCards;
public:
    Player(const string& playerName);
    ~Player();

    void addCardToBench(Card* card);
    void activatePokemonCard(size_t cardIndex);
    void attachEnergyCard(size_t const pokemonIndex, size_t const energyIndex);
    void attack(size_t const pokemonIndex, size_t const attackIndex, Player& player, size_t const enemyPokemonIndex);
    void useTrainer(size_t const trainerIndex);

    void displayBench() const;
    void displayAction() const;
    void displayInfo() const;
};


#endif //POKEMONTRADINGCARDGAME_PLAYER_H
