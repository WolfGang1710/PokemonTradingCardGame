//
// Created by ecole on 21/12/2023.
//

#ifndef POKEMONTRADINGCARDGAME_POKEMONCARD_H
#define POKEMONTRADINGCARDGAME_POKEMONCARD_H

#include <string>
#include <vector>
#include "Card.h"
#include "Attacks.h"

using namespace std;

class PokemonCard: public Card {
private:
    string pokemonType;
    string familyName;
    int evolutionLevel;
    int maxHP;
    int hp;
    Attacks attacks;
    /*
     * Vecteur d'attack
     * 1 attack = 1 struct = 1 tuple
     * 1 tuple = cout en énergie, cout en énergie actuel, descriptoin, dégât
     */
public:
    PokemonCard(string, string, string, )
};


#endif //POKEMONTRADINGCARDGAME_POKEMONCARD_H
