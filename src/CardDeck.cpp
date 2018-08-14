/*
 * @author Pawel Ptasznik
 */

#include "CardDeck.hpp"

bool Card::operator <(const Card& rhs) const
{
    if (cardNumber_ != rhs.cardNumber_)
    {
        return cardNumber_ < rhs.cardNumber_;
    }
    else
    {
        return instanceId_ < rhs.instanceId_;
    }
}

CardDeck::CardDeck(): logger_("CardDeck")
{
    logger_.debug("CTor");
}

bool CardDeck::addCard(const Card& card)
{
    logger_.debug("addCard: location " + std::to_string(card.location_));
    bool result = false;
    switch(card.location_)
    {
        case 0:
        {
            auto res = hand_.insert(card);
            result = res.second;
            break;
        }
        case 1:
        {
            auto res = heroSide_.insert(card);
            result = res.second;
            break;
        }
        case -1:
        {
            auto res = opponentSide_.insert(card);
            result = res.second;
            break;
        }
        default:
        {
            logger_.info("Unsupported location: " + std::to_string(card.location_));
            break;
        }
    }
    return result;
}

bool CardDeck::resetHand()
{
    logger_.debug("resetHand");
    if (hand_.empty())
    {
        return false;
    }
    hand_.clear();
    return true;
}

bool CardDeck::resetHeroSide()
{
    if (heroSide_.empty())
    {
        return false;
    }
    heroSide_.clear();
    return true;
}

bool CardDeck::resetOpponentSide()
{
    if (opponentSide_.empty())
    {
        return false;
    }
    opponentSide_.clear();
    return true;
}

bool CardDeck::resetAll()
{
    return resetHand() && resetHeroSide() && resetOpponentSide();
}


std::set<Card> CardDeck::getHand() const
{
    return hand_;
}

std::set<Card> CardDeck::getHeroSide() const
{
    return heroSide_;
}
