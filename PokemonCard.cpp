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
    /*
     * @brief Constructor of PokemonCard
     * @details Constructor of PokemonCard, it initializes the attributes of the PokemonCard :
     * - active : false
     * - actualCost : 0
     * and it creates the attacks of the PokemonCard using the emplace_back method
     * @param: `_cardName`: string
     * @param: `_pokemonType`: string
     * @param: `_familyType`: string
     * @param: `_evolutionLevel`: int
     * @param: `_maxHP`: int
     * @param: `cost1`: int
     * @param: `attackName1`: string
     * @param: `damage1`: int
     * @param: `cost2`: int
     * @param: `attackName2`: string
     * @param: `damage2`: int
     * @return: None
     */
    active = false; //par défaut la carte n'est pas active
    actualCost = 0; //par défaut le coût de la carte est de 0

    // Ajout des attaques
    // emplace_back créé le tuple directement et évite la copie
    attacks.emplace_back(cost1, cost1, attackName1, damage1);
    attacks.emplace_back(cost2, cost2, attackName2, damage2);
}

void PokemonCard::activate() {
    /*
     * @brief: Activates the PokemonCard
     * @details: Activates the PokemonCard, if it is not already active (default state)
     * @return: None
     */
    if(!active) {
        active = true;
    } else {
        cout << endl << "Pokemon Card " << cardName << " is already active";
    }
}

void PokemonCard::incrementActualCost() {
    /*
     * @brief: Increments the actual cost of the PokemonCard by one
     * @return: None
     */
    actualCost++;
}

void PokemonCard::receiveDamage(const int damage) {
    /*
     * @brief: Receives damage
     * @details: Receives damage, set dead to true if the PokemonCard's hp is less than or equal to 0
     * @param: `damage`: int
     * @return: None
     */
    hp -= damage;
    if (hp <= 0) {
        dead = true;
    }
}

bool PokemonCard::ableToAttack(const int cost) const {
    /*
     * @brief: Checks if the PokemonCard is able to attack
     * @details: Checks if the PokemonCard is able to attack, if it is active, not dead and if the cost is less than or equal to the actual cost
     * @param: `cost`: int
     * @return: bool
     * @warning: Not used yet
     */
    return (active && !dead && cost <= actualCost);
}

const string &PokemonCard::getPokemonType() const {
    /*
     * @brief: Returns the Pokémon type of the PokemonCard
     * @return: pokemonType: string
     */
    return pokemonType;
}

const string &PokemonCard::getFamilyType() const {
    /*
     * @brief: Returns the family type of the PokemonCard
     * @return: familyType: string
     */
    return familyType;
}

int PokemonCard::getEvolutionLevel() const {
    /*
     * @brief: Returns the evolution level of the PokemonCard
     * @return: evolutionLevel: int
     */
    return evolutionLevel;
}

int PokemonCard::getHP() const {
    /*
     * @brief: Returns the HP of the PokemonCard
     * @return: hp: int
     */
    return hp;
}

const vector<tuple<int, int, string, int>> &PokemonCard::getAttacks() const {
    /*
     * @brief: Returns the attacks of the PokemonCard
     * @return: attacks: vector<tuple<int, int, string, int>>
     */
    return attacks;
}

const tuple<int, int, string, int> &PokemonCard::getAttack(const size_t attackIndex) const {
    /*
     * @brief: Returns the attack at the given index
     * @param: `attackIndex`: size_t
     * @return: attack: tuple<int, int, string, int>
     */
    if(attackIndex < attacks.size()) {
        return attacks[attackIndex];
    } else {
        cout << endl << "Invalid attack index";
    }
}

size_t PokemonCard::getNumberOfAttacks() const {
    /*
     * @brief: Returns the number of attacks of the PokemonCard
     * @return: attacks.size(): size_t
     */
    return attacks.size();
}

int PokemonCard::getMaxHp() const {
    /*
     * @brief: Returns the max HP of the PokemonCard
     * @return: maxHP: int
     */
    return maxHP;
}

int PokemonCard::getActualCost() const {
    /*
     * @brief: Returns the actual cost of the PokemonCard
     * @return: actualCost: int
     * @warning: Not used yet
     */
    return actualCost;
}

bool PokemonCard::isActive() const {
    /*
     * @brief: Returns the active state of the PokemonCard
     * @return: active: bool
     * @warning: Not used yet
     */
    return active;
}

bool PokemonCard::isDead() const {
    /*
     * @brief: Returns the dead state of the PokemonCard
     * @return: dead: bool
     * @warning: Not used yet
     */
    return dead;
}

void PokemonCard::displayInfo() const {
    /*
     * @brief: Displays the information of the PokemonCard
     * @details: Displays the information of the PokemonCard :
     * - Pokemon name
     * - Pokemon type
     * - Family type
     * - Evolution level
     * - max HP
     * - the current HP
     * - the attacks and their details
     * @return: None
     *
     * @bug: Displaying the actual cost of the PokemonCard isn't working properly.
     */
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
    /*
     * @brief: Sets the HP of the PokemonCard
     * @details: Sets the HP of the PokemonCard, used by the TrainerCard
     * @param: _hp: int
     * @return: None
     */
    hp = _hp;
}

