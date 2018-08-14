#pragma once

/*
 * @author Pawel Ptasznik
 */

#include <set>
#include <string>
#include "Logger.hpp"

struct Card
{
public:
    Card() = default;
    Card(const Card& other) = default;
    Card(Card&& other) = default;
    bool operator <(const Card& rhs) const;
    int cardNumber_;
    int instanceId_;
    int location_;
    int cardType_;
    int cost_;
    int attack_;
    int defense_;
    std::string abilities_;
};

class CardDeck
{
public:
    CardDeck();
    bool addCard(const Card& card);
    bool resetHand();
    bool resetHeroSide();
    bool resetOpponentSide();
    bool resetAll();
    std::set<Card> getHand() const;
    std::set<Card> getHeroSide() const;
private:
    Logger logger_;
    std::set<Card> hand_;
    std::set<Card> heroSide_;
    std::set<Card> opponentSide_;
};
