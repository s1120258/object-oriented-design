#ifndef CARD_H
#define CARD_H

enum Suit { Hearts, Diamonds, Clubs, Spades };
enum Rank { Two = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

struct Card {
    Suit suit;
    Rank rank;

    Card(Suit s, Rank r) : suit(s), rank(r) {}
};

#endif // CARD_H