//
// Created by ecole on 05/01/2024.
//

#include "headers/Player.h"
#include "headers/EnergyCard.h"
#include <iostream>


Player::Player(const string& _playerName):
playerName(_playerName)
{
}

Player::~Player() {
    for (auto& card : benchCards) {
        delete card;
    }
    for (auto& pokemonCard : actionCards) {
        delete pokemonCard;
    }
}

void Player::addCardToBench(Card* card) {
    /*
     *
     */
    if(PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(card)) {
        actionCards.push_back(pokemonCard);
    } else if(TrainerCard* trainerCard = dynamic_cast<TrainerCard*>(card)) {
        trainerCards.push_back(trainerCard);
    } else {
        benchCards.push_back(card);
    }
}

void Player::activatePokemonCard(size_t cardIndex) {
    /*
     *
     */
    // pas besoin de vérifier si cardIndex < 0 car size_t est un unsigned int
    if (cardIndex < actionCards.size()) {
        dynamic_cast<PokemonCard*>(actionCards[cardIndex])->activate();
        cout << endl << playerName << " is activating a Pokemon Card: " << actionCards[cardIndex]->getCardName();
    } else {
        // benchCards[cardIndex]->activate(); // Ne fonctionne pas car la méthode activate n'est pas définie dans Card
        cerr << "Invalid card index" << endl;
    }
}

void Player::attachEnergyCard(const size_t pokemonIndex, const size_t energyIndex) {
    /*
     *
     */

    if(pokemonIndex < actionCards.size() && energyIndex < benchCards.size()) {
        PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(actionCards[pokemonIndex]);
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyIndex]);
        if(pokemonCard && energyCard) {
            pokemonCard->incrementActualCost();
            benchCards.erase(benchCards.begin() + energyIndex);
            cout << endl << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType() << " to the Pokemon " << pokemonCard->getCardName();
        } else {
            cerr << "Invalid card type" << endl;
        }
    }
}

void Player::attack(const size_t attackerIndex, const size_t attackIndex, Player &opponent, const size_t enemyPokemonIndex) {
    /*
     *
     */
    if (attackerIndex < actionCards.size() && enemyPokemonIndex < opponent.actionCards.size()) {
        PokemonCard* attacker = dynamic_cast<PokemonCard*>(actionCards[attackerIndex]);
        PokemonCard* enemyPokemon = dynamic_cast<PokemonCard*>(opponent.actionCards[enemyPokemonIndex]);

        // Vérifier si les cartes sont du bon type
        if (attacker && enemyPokemon) {
            // Vérifier si l'indice de l'attaque est valide
            if (attackIndex < attacker->getNumberOfAttacks()) {
                // Récupérer les informations sur l'attaque
                auto& attack = attacker->getAttack(attackIndex);
                int energyCost = get<0>(attack);
                int currentEnergy = get<1>(attack);

                // Vérifier si le Pokémon attaquant a assez d'énergie
                if (currentEnergy >= energyCost) {
                    // Effectuer l'attaque
                    cout << endl << playerName << " attacking " << opponent.playerName << "'s Pokemon "
                         << opponent.actionCards[enemyPokemonIndex]->getCardName()
                         << " with the Pokemon " << actionCards[attackerIndex]->getCardName()
                         << " with its attack: " << get<2>(attack) ;

                    // Appliquer les dégâts au Pokémon attaqué
                    enemyPokemon->receiveDamage(get<3>(attack));
                    cout << endl << "Reducing " << get<3>(attack) << " from " << opponent.playerName << "'s Pokemon's HP" ;

                    // Vérifier si le Pokémon attaqué est éliminé
                    if (enemyPokemon->getHP() <= 0) {
                        cout << endl << opponent.actionCards[enemyPokemonIndex]->getCardName() << " fainted.";
                    } else {
                        cout << endl << "Pokemon " << opponent.actionCards[enemyPokemonIndex]->getCardName() << " is still alive.";
                    }
                } else {
                    cerr << "Error: Not enough energy to perform the attack." << endl;
                }
            } else {
                cerr << "Error: Invalid attack index." << endl;
            }
        } else {
            cerr << "Error: Invalid types for attacking Pokémon." << endl;
        }
    } else {
        cerr << "Error: Invalid indices for attacking Pokémon." << endl;
    }
}

void Player::useTrainer(const size_t trainerIndex) {
    /*
     *
     */
    if (trainerIndex < trainerCards.size()) {
        TrainerCard* trainerCard = trainerCards[trainerIndex];
        cout << endl << playerName << " is using the Trainer Card to " << '"' << trainerCard->getTrainerEffect() << '"';
        for (auto& pokemonCard : actionCards) {
            pokemonCard->setHp(pokemonCard->getMaxHp());
        }
        trainerCards.erase(trainerCards.begin() + trainerIndex);
    } else {
        cerr << "Error: Invalid trainer index." << endl;
    }
}

void Player::displayBench() const {
    size_t i = 0;
    cout << endl << "Bench cards for Player " << playerName << " :" ;
    for(TrainerCard *trainerCard : trainerCards){
        cout << endl << "Trainer Card - Name: " << trainerCard->getCardName() << ", Effect: " << trainerCard->getTrainerEffect();
    }
    for(PokemonCard *pokemonCard : actionCards){
        cout << endl << "Pokemon Card - Name: " << pokemonCard->getCardName() << ", Type: " << pokemonCard->getPokemonType()
             << ", Evolution Level: " << pokemonCard->getEvolutionLevel() << " of the family \"" << pokemonCard->getFamilyType() << '"'
             << ", HP: " << pokemonCard->getHP() ;
    }
}

void Player::displayAction() const {
    size_t j = 0;
    cout << endl << "Attacks:";
    for(PokemonCard *pokemonCard : actionCards){
        for(auto &attack : pokemonCard->getAttacks()){
            cout << endl << "Attack #" << j << ":"; j++;
            cout << endl << "Attack cost: " << get<0>(attack);
            cout << endl << "Attack current energy storage: " << get<1>(attack);
            cout << endl << "Attack description: " << get<2>(attack);
            cout << endl << "Attack damage: " << get<3>(attack);
        }
    }
}

void Player::displayInfo() const {
    cout << endl << "Player: " << playerName << endl;
    cout << "Bench cards: " << endl;
    for (auto& card : benchCards) {
        card->displayInfo();
    }
    cout << "Action cards: " << endl;
    for (auto& pokemonCard : actionCards) {
        pokemonCard->displayInfo();
    }
}
