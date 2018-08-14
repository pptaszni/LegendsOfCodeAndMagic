/*
 * @author Pawel Ptasznik
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Decision.hpp"


class DecisionShould: public ::testing::Test {
protected:
    DecisionShould() {}
    Decision sut_;
};

TEST_F(DecisionShould, pickCardWithTheBestCostAttackRatio)
{
    Card weakCard1;
    Card weakCard2;
    Card bestCard;
    weakCard1.location_ = 0;
    weakCard2.location_ = 0;
    bestCard.location_ = 0;
    weakCard1.cardNumber_ = 1;
    weakCard2.cardNumber_ = 2;
    bestCard.cardNumber_ = 3;
    weakCard1.attack_ = 1;
    weakCard1.cost_ = 5;
    weakCard2.attack_ = 3;
    weakCard2.cost_ = 5;
    bestCard.attack_ = 5;
    bestCard.cost_ = 4;
    std::vector<Card> cards;
    cards.push_back(weakCard1);
    cards.push_back(weakCard2);
    cards.push_back(bestCard);
    Player testPlayer("TestPlayer");
    int chosenCardPos = sut_.pickACardInDraftPhase(testPlayer, cards);
    ASSERT_EQ(2, chosenCardPos);
}
