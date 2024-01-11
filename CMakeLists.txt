cmake_minimum_required(VERSION 3.27)
project(PokemonTradingCardGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(PokemonTradingCardGame main.cpp
        Card.cpp
        headers/Card.h
        PokemonCard.cpp
        headers/PokemonCard.h
        EnergyCard.cpp
        headers/EnergyCard.h
        TrainerCard.cpp
        headers/TrainerCard.h
        Player.cpp
        headers/Player.h)
