//
// Created by ecole on 05/01/2024.
//

#include "headers/PokemonCard.h"

PokemonCard::PokemonCard(const string &_cardName, const string &_pokemonType, const string &_familyType,
                         const int _evolutionLevel, const int _maxHP, const int cost1, const string &attackName1,
                         const int damage1, const int cost2, const string &attackName2, const int damage2) :

Card(_cardName),
pokemonType(_pokemonType),
familyType(_familyType),
evolutionLevel(_evolutionLevel),
maxHP(_maxHP),
hp(_maxHP),
actualCost(0)
{
    active = false; //par défaut la carte n'est pas active
    actualCost = 0; //par défaut le coût de la carte est de 0

    // Ajout des attaques
    // emplace_back créé le tuple directement et évite la copie
    attacks.emplace_back(cost1, cost1, attackName1, damage1);
    attacks.emplace_back(cost2, cost2, attackName2, damage2);
}

void PokemonCard::activate() {
    if(!active) {
        active = true;
    } else {
        cout << endl << "Pokemon Card " << cardName << " is already active";
    }
}

void PokemonCard::incrementActualCost() {
    actualCost++;
}

void PokemonCard::receiveDamage(const int damage) {
    hp -= damage;
    if (hp <= 0) {
        dead = true;
    }
}

bool PokemonCard::ableToAttack(const int cost) const {
    return (active && !dead && cost <= actualCost);
}

const string &PokemonCard::getPokemonType() const {
    return pokemonType;
}

const string &PokemonCard::getFamilyType() const {
    return familyType;
}

int PokemonCard::getEvolutionLevel() const {
    return evolutionLevel;
}

int PokemonCard::getHP() const {
    return hp;
}

const vector<tuple<int, int, string, int>> &PokemonCard::getAttacks() const {
    return attacks;
}

const tuple<int, int, string, int> &PokemonCard::getAttack(const size_t attackIndex) const {
    if(attackIndex < attacks.size()) {
        return attacks[attackIndex];
    } else {
        cout << endl << "Invalid attack index";
    }
}

size_t PokemonCard::getNumberOfAttacks() const {
    return attacks.size();
}

int PokemonCard::getMaxHp() const {
    return maxHP;
}

int PokemonCard::getHp() const {
    return hp;
}

int PokemonCard::getActualCost() const {
    return actualCost;
}

bool PokemonCard::isActive() const {
    return active;
}

bool PokemonCard::isDead() const {
    return dead;
}

void PokemonCard::displayInfo() const {
    cout << endl << "Pokemon Card Information:";
    Card::displayInfo(); //Affiche le nom de la carte

    // Affichage des caractéristiques du Pokémon
    cout << endl << "Pokemon Type: " << pokemonType;
    cout << endl << "Family Type: " << familyType;
    cout << endl << "Evolution Level: " << evolutionLevel;
    cout << endl << "Max HP: " << maxHP;
    cout << endl << "Current HP: " << hp;

    // Affichage des attaques
    cout << endl << "Attacks: ";
    for (const auto& attack : attacks) {
        cout << endl << "\tCost: " << get<0>(attack);
        cout << endl << "\tActual Cost: " << get<1>(attack);
        cout << endl << "\tDescription: " << get<2>(attack);
        cout << endl << "\tDamage: " << get<3>(attack);
    }
}

void PokemonCard::setHp(int _hp) {
    hp = _hp;
}

