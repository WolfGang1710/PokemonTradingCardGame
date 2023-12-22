//
// Created by ecole on 22/12/2023.
//

#include <ostream>
#include <iostream>
#include "headers/Player.h"
using namespace std;

Player::Player(string _playerName):
    playerName(_playerName)
{
}

void Player::addCardToBench(Card * card) {
    benchCards.push_back(card);
    cout << endl << "Card added to bench" ;
}

void Player::activatePokemonCard(const int index) {
    string pokemonName = benchCards[index]->PokemonCard.getCardName();
    string _playerName = getPlayerName();
    cout << endl << _playerName << " activating a Pokemon Card :" << pokemonName;

}

void Player::attachEnergyCard(const int pokemonIndex, const int energyCardIndex) {
    string pokemonName = benchCards[pokemonIndex]->PokemonCard.getCardName();
    string energyCardName = benchCards[energyCardIndex]->EnergyCard.getCardName();
    string energyType = getEnergyType();
    string _playerName = getPlayerName();
    cout << endl << _playerName << " is attaching Energy Card of type" << energyType << " to the Pokemon " << pokemonName;
    removeCardFromBench(energyCardIndex);
}

void Player::displayBench() {

}

void Player::displayAction() {

}

void Player::attack(const int, const int, const Player, const int) {

}

string Player::getPlayerName() const {
    return playerName;
}

void Player::removeCardFromBench(const int index) {

}
