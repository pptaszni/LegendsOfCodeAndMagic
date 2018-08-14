/*
 * @author Pawel Ptasznik
 */

#include <iostream>
#include <string>
#include "Decision.hpp"
#include "GameController.hpp"


GameController::GameController(std::istream& input, std::ostream& output):
    input_(input),
    output_(output),
    logger_("GameController"),
    hero_("Hero"),
    opponent_("BadGuy"),
    deck_(),
    draftPhaseCards_(),
    roundNumber_(0)
{
    logger_.debug("CTor");
}

bool GameController::executeIteration()
{
    roundNumber_++;
    logger_.debug("executeIteration: " + std::to_string(roundNumber_));
    readInputStream();
    Decision decision;
    if (roundNumber_ < 30)
    {
        int pick = decision.pickACardInDraftPhase(hero_, draftPhaseCards_);
        draftPhaseCards_.clear();
        output_ << createPickCommand(pick) << std::endl;
        return true;
    }
    std::string cmd = decision.summonAttackOrPass(hero_, deck_);
    deck_.resetAll();
    output_ << cmd << std::endl;
    return true;
}

void GameController::readInputStream()
{
    for (auto p : {&hero_, &opponent_})
    {
        int health;
        int mana;
        int deck;
        int rune;
        input_ >> health >> mana >> deck >> rune;
        input_.ignore();
        p->updateParams(health, mana, deck, rune);
    }
    int opponentHand;
    input_ >> opponentHand; input_.ignore();
    int cardCount;
    input_ >> cardCount; input_.ignore();
    Card card;
    for (int i = 0; i < cardCount; i++) {
        input_ >> card.cardNumber_;
        input_ >> card.instanceId_;
        input_ >> card.location_;
        input_ >> card.cardType_;
        input_ >> card.cost_;
        input_ >> card.attack_;
        input_ >> card.defense_;
        input_ >> card.abilities_;
        int myHealthChange;
        int opponentHealthChange;
        int cardDraw;
        input_ >> myHealthChange >> opponentHealthChange >> cardDraw;
        input_.ignore();
        if (roundNumber_ < 30)
        {
            draftPhaseCards_.push_back(card);
        }
        else
        {
            deck_.addCard(card);
        }
    }
}

std::string GameController::createPickCommand(int num)
{
    std::string command("PICK ");
    command += std::to_string(num);
    return command;
}
