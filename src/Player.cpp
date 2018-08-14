/*
 * @author Pawel Ptasznik
 */

#include "Player.hpp"

Player::Player(const std::string& name): logger_(name)
{
    logger_.debug("CTor");
}

int Player::getHealth() const
{
    return health_;
}

int Player::getMana() const
{
    return mana_;
}

int Player::getDeck() const
{
    return deck_;
}

int Player::getRune() const
{
    return rune_;
}

bool Player::updateParams(int health, int mana, int deck, int rune)
{
    logger_.debug("h: " + std::to_string(health)
        + " m: " + std::to_string(mana)
        + " d: " + std::to_string(deck)
        + " r: " + std::to_string(rune));
    health_ = health;
    mana_ = mana;
    deck_ = deck;
    rune_ = rune;
    return true;
}
