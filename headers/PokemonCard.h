//
// Created by ecole on 05/01/2024.
//

#ifndef POKEMONTRADINGCARDGAME_POKEMONCARD_H
#define POKEMONTRADINGCARDGAME_POKEMONCARD_H

#include <vector>
#include <tuple>
#include <string>
#include "Card.h"

using namespace std;

class PokemonCard : public Card{
private:
    string pokemonType;
    string familyType;
    int evolutionLevel;
    int maxHP;
    int hp;
    int actualCost;
    vector<tuple<int, int, string, int>> attacks; // <cost, actualCost, description, damage>
    bool active;
    bool dead;

public:
    PokemonCard(const string &cardName, const string &pokemonType, const string &familyType,
                const int evolutionLevel, const int maxHP,
                const int cost1, const string &attackName1, const int damage1,
                const int cost2, const string &attackName2, const int damage2);

    virtual ~PokemonCard() = default;
    void activate();
    void incrementActualCost();
    void receiveDamage(const int damage);
    bool ableToAttack(const int cost) const;

    const string &getPokemonType() const;
    const string &getFamilyType() const;
    int getEvolutionLevel() const;
    int getHP() const;
    const vector<tuple<int, int, string, int>> &getAttacks() const;
    const tuple<int, int, string, int> &getAttack(const size_t attackIndex) const;
    size_t getNumberOfAttacks() const ;
    int getMaxHp() const;
    void setHp(int hp);
    int getActualCost() const;

    bool isActive() const;
    bool isDead() const;

    void displayInfo() const override;
};


#endif //POKEMONTRADINGCARDGAME_POKEMONCARD_H
