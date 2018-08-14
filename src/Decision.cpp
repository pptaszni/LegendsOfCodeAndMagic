/*
 * @author Pawel Ptasznik
 */

#include <algorithm>
#include <vector>
#include "Decision.hpp"

Decision::Decision(): logger_("Decision")
{}

int Decision::pickACardInDraftPhase(const Player& /*hero*/, const std::vector<Card>& cards)
{
    logger_.debug("pickACardInDraftPhase");
    auto best = std::max_element(cards.begin(), cards.end(),
        [](const Card& lhs, const Card& rhs)
        {
            return (lhs.attack_ - lhs.cost_) < (rhs.attack_ - rhs.cost_);
        });
    return std::distance(cards.begin(), best);
}

std::string Decision::summonAttackOrPass(const Player& hero, const CardDeck& deck)
{
    auto hand = deck.getHand();
    auto myCreatures = deck.getHeroSide();
    auto strongestCreature = std::max_element(myCreatures.begin(), myCreatures.end(),
        [](const Card& lhs, const Card& rhs)
        {
            return lhs.attack_ < rhs.attack_;
        });
    if (strongestCreature != myCreatures.end())
    {
        return "ATTACK " + std::to_string(strongestCreature->instanceId_) + " -1";
    }
    auto cheapestCard = std::min_element(hand.begin(), hand.end(),
        [](const Card& lhs, const Card& rhs)
        {
            return lhs.cost_ < rhs.cost_;
        });
    if (hero.getMana() >= cheapestCard->cost_)
    {
        return "SUMMON " + std::to_string(cheapestCard->instanceId_);
    }
    return "PASS";
}
