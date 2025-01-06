#ifndef CARDGAME_H
#define CARDGAME_H

#include <vector>
#include "Card.h"

class CardGame {
public:
    CardGame();
    virtual void play() = 0;

protected:
    std::vector<Card> deck;

private:
    void createDeck();
    void shuffleDeck();
};

#endif // CARDGAME_H