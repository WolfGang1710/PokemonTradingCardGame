//
// Created by ecole on 21/12/2023.
//

#include "headers/PokemonCard.h"

PokemonCard::PokemonCard(string _pokemonName, string _pokemonType, string _familyName,
                         int _evolutionLevel, int _maxHP, int _hp, Attacks _attacks):
        pokemonName(_pokemonName),
        pokemonType(_pokemonType),
        familyName(_familyName),
        evolutionLevel(_evolutionLevel),
        maxHP(_maxHP),
        hp(_hp),
        attacks(_attacks)
{
}

string PokemonCard::getPokemonName() const {
    return pokemonName;
}

string PokemonCard::getPokemonType() const {
    return pokemonType;
}

string PokemonCard::getFamilyName() const {
    return familyName;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

int PokemonCard::getMaxHP() const {
    return maxHP;
}

int PokemonCard::getHP() const {
    return hp;
}

Attacks PokemonCard::getAttacks() const {
    return attacks;
}


