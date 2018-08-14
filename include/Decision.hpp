#pragma once

/*
 * @author Pawel Ptasznik
 */

#include <vector>
#include "CardDeck.hpp"
#include "Logger.hpp"
#include "Player.hpp"

class Decision {
public:
    Decision();
    int pickACardInDraftPhase(const Player& hero, const std::vector<Card>& cards);
    std::string summonAttackOrPass(const Player& hero, const CardDeck& deck);
private:
    Logger logger_;
};
