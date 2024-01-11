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
    /**
     * @brief: add a card to the bench
     * @details: if it is a PokemonCard, add it to the actionCards vector, if it is a TrainerCard, add it to the trainerCards vector, otherwise add it to the benchCards vector
     * @param: `card`: pointer to the card to add
     * @return: none
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
    /**
     * @brief: activate a PokemonCard
     * @details: if the cardIndex is valid, activate the PokemonCard at the given index
     * @param: `cardIndex`: index of the PokemonCard to activate
     * @return: none
     * @bug : When running the program, the error is raised, but not at the same place, but the program continues to run.
     */
    // pas besoin de vérifier si cardIndex < 0 car size_t est un unsigned int
    if (cardIndex < actionCards.size()) {
        dynamic_cast<PokemonCard*>(actionCards[cardIndex])->activate();
        cout << endl << playerName << " is activating a Pokemon Card: " << actionCards[cardIndex]->getCardName();
    } else {
        // benchCards[cardIndex]->activate(); // Ne fonctionne pas car la méthode activate n'est pas définie dans Card
        cerr << endl << "Invalid card index, pokemon not activated ; Card index: " << cardIndex << " from player " << playerName << endl;
    }
}

void Player::attachEnergyCard(const size_t pokemonIndex, const size_t energyIndex) {
    /**
     * @brief: attach an EnergyCard to a PokemonCard
     * @details: if the pokemonIndex and energyIndex are valid, attach the EnergyCard at the given index to the PokemonCard at the given index
     * @param: `pokemonIndex`: index of the PokemonCard to attach the EnergyCard to
     * @param: `energyIndex`: index of the EnergyCard to attach to the PokemonCard
     * @return: none
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
    /**
     * @brief: attack an opponent's PokemonCard
     * @details: if the attackerIndex, attackIndex and enemyPokemonIndex are valid, attack the opponent's PokemonCard at the given index with the PokemonCard at the given index. If the opponent's PokemonCard is eliminated, remove it from the opponent's actionCards vector
     * @param: `attackerIndex`: index of the PokemonCard to attack with
     * @param: `attackIndex`: index of the attack to use
     * @param: `opponent`: reference to the opponent
     * @param: `enemyPokemonIndex`: index of the PokemonCard to attack
     * @return: none
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
                        opponent.actionCards.erase(opponent.actionCards.begin() + enemyPokemonIndex);
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
    /**
     * @brief: use a TrainerCard
     * @details: if the trainerIndex is valid, use the TrainerCard at the given index. Since the only one trainerEffect is "heal all your Pokemon", set the HP of all the PokemonCards in the actionCards vector to their max HP
     * @param: `trainerIndex`: index of the TrainerCard to use
     * @return: none
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
    /**
     * @brief: display the bench
     * @details: display the benchCards vector
     * @param: none
     * @return: none
     */
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
    /**
     * @brief: display the action cards
     * @details: display the actionCards vector
     * @param: none
     * @return: none
     */
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
    /**
     * @brief: display the player's name and all the cards
     * @details: display the playerName, the benchCards vector and the actionCards vector
     * @param: none
     * @return: none
     */
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
