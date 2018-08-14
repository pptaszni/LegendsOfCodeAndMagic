/*
 * @author Pawel Ptasznik
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "CardDeck.hpp"


class CardDeckShould: public ::testing::Test {
protected:
    CardDeckShould() {}
    CardDeck sut_;
};

TEST_F(CardDeckShould, addCardToAppropriateSet)
{
    int numOf = 69;
    Card inHand;
    Card onHeroSide;
    Card onOpponentSide;
    inHand.location_ = 0;
    inHand.cardNumber_ = 1;
    onHeroSide.location_ = 1;
    onHeroSide.cardNumber_ = 2;
    onOpponentSide.location_ = -1;
    onOpponentSide.cardNumber_ = 3;
    for (int i = 0; i < numOf; i++)
    {
        inHand.instanceId_ = i;
        ASSERT_TRUE(sut_.addCard(inHand));
        onHeroSide.instanceId_ = i;
        ASSERT_TRUE(sut_.addCard(onHeroSide));
        onOpponentSide.instanceId_ = i;
        ASSERT_TRUE(sut_.addCard(onOpponentSide));
    }
    ASSERT_FALSE(sut_.addCard(inHand));
    ASSERT_FALSE(sut_.addCard(onHeroSide));
    ASSERT_FALSE(sut_.addCard(onOpponentSide));
    auto hand = sut_.getHand();
    ASSERT_EQ(numOf, hand.size());
}

TEST_F(CardDeckShould, returnFalseWHenResetEmptySetAndTruWhenFull)
{
    Card c;
    c.location_ = 0;
    c.cardNumber_ = 1;
    ASSERT_FALSE(sut_.resetHand());
    sut_.addCard(c);
    ASSERT_TRUE(sut_.resetHand());
    c.location_ = 1;
    ASSERT_FALSE(sut_.resetHeroSide());
    sut_.addCard(c);
    ASSERT_TRUE(sut_.resetHeroSide());
    c.location_ = -1;
    ASSERT_FALSE(sut_.resetOpponentSide());
    sut_.addCard(c);
    ASSERT_TRUE(sut_.resetOpponentSide());
}
