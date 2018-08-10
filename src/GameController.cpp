/*
 * @author Pawel Ptasznik
 */

#include <iostream>
#include <string>
#include "GameController.hpp"


GameController::GameController(std::istream& input, std::ostream& output):
    input_(input),
    output_(output),
    logger_("GameController")
{
    logger_.debug("CTor");
}

bool GameController::executeIteration()
{
    logger_.debug("executeIteration");
    for (int i = 0; i < 2; i++) {
        int playerHealth;
        int playerMana;
        int playerDeck;
        int playerRune;
        input_ >> playerHealth >> playerMana >> playerDeck >> playerRune; input_.ignore();
    }
    int opponentHand;
    input_ >> opponentHand; input_.ignore();
    int cardCount;
    input_ >> cardCount; input_.ignore();
    for (int i = 0; i < cardCount; i++) {
        int cardNumber;
        int instanceId;
        int location;
        int cardType;
        int cost;
        int attack;
        int defense;
        std::string abilities;
        int myHealthChange;
        int opponentHealthChange;
        int cardDraw;
        input_ >> cardNumber >> instanceId >> location >> cardType >> cost >> attack >> defense >> abilities >> myHealthChange >> opponentHealthChange >> cardDraw; input_.ignore();
    }
    output_ << "PASS" << std::endl;
    return true;
}
