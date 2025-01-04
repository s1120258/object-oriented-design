#include "CardGame.h"
#include <algorithm>
#include <random>
#include <ctime>

CardGame::CardGame() {
    createDeck();
    shuffleDeck();
}

void CardGame::createDeck() {
    for (int s = Hearts; s <= Spades; ++s) {
        for (int r = Two; r <= Ace; ++r) {
            deck.emplace_back(static_cast<Suit>(s), static_cast<Rank>(r));
        }
    }
}

void CardGame::shuffleDeck() {
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(static_cast<unsigned>(std::time(0))));
}
