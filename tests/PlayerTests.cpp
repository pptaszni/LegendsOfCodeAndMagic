/*
 * @author Pawel Ptasznik
 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "Player.hpp"


class PlayerShould: public ::testing::Test {
protected:
    PlayerShould(): sut_("TestPlayer") {}
    Player sut_;
};

TEST_F(PlayerShould, getPreviouslySetParameters)
{
    int health(68);
    int mana(69);
    int deck(70);
    int rune(71);
    sut_.updateParams(health, mana, deck, rune);
    ASSERT_EQ(health, sut_.getHealth());
    ASSERT_EQ(mana, sut_.getMana());
    ASSERT_EQ(deck, sut_.getDeck());
    ASSERT_EQ(rune, sut_.getRune());
}
