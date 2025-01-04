#ifndef CARDGAME_H
#define CARDGAME_H

#include <vector>
#include "Card.h"

class CardGame {
protected:
    std::vector<Card> deck;

    void createDeck();
    void shuffleDeck();

public:
    CardGame();
    virtual void play() = 0;
};

#endif // CARDGAME_H