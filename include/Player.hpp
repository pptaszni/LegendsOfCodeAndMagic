#pragma once

/*
 * @author Pawel Ptasznik
 */

#include "Logger.hpp"

class Player {
public:
    Player() = delete;
    Player(const std::string& name);
    Player(const Player& other) = delete;
    Player(Player&& other) = delete;
    int getHealth() const;
    int getMana() const;
    int getDeck() const;
    int getRune() const;
    bool updateParams(int health, int mana, int deck, int rune);

private:
    Logger logger_;
    int health_;
    int mana_;
    int deck_;
    int rune_;
};
