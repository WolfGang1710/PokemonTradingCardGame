# PokemonTradingCardGame
> Un jeu de cartes Pokemon en C++.
> ROGUET William 2e année Informatique & Réseaux à l'ENSISA.

## Choix d'implémentation

J'avais tout d'abord fait le choix d'implémenter les attaques des pokémons en passant par une structure, par souci de lecture et de compréhension du code.
J'ai finalement décidé de passer les données de manières brutes, sans passer par une structure.

## Problèmes

1. Lors de l'utilisation de `displayAction`, je constate que actualCost augmente à chaque itération dans la boucle `for`.
2. Lors de l'utilisation de `displayAction`, je constate que les actualCosts de Bulbizarre sont les mêmes que ceux de Pikachu.
3. Lors de la compilation, j'obtiens une fois une erreur `Invalid card index` qui apparait soit au touu début soit au milieu du script.

## Structure du projet

```
PokemonTradingCardGame
|.gitignore
|   Card.cpp
|   CMakeLists.txt
|   EnergyCard.cpp
|   logo.png
|   main.cpp
|   Player.cpp
|   PokemonCard.cpp
|   README.md
|   TrainerCard.cpp
|   tree.txt
|   
|       
+---Doxygen # Documentation
|
|           
\---headers
    Card.h
    EnergyCard.h
    Player.h
    PokemonCard.h
    TrainerCard.h
```

## TODO

- [x] Créer les classes de cartes
- [x] Créer les classes de cartes EnergyCard
- [x] Créer les classes de cartes PokemonCard
- [x] Créer les classes de cartes TrainerCard
- [x] Créer les classes de cartes Player
- [ ] Fixer les problèmes des actualCost
- [ ] Implémenter la limitation à deux attaques (actuellement, pas de limite)