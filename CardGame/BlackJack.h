#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "CardGame.h"

class BlackJack : public CardGame {
private:
	void drawCard(std::vector<Card>& hand);
	int getCardValue(const Card& card);
	int getHandValue(const std::vector<Card>& hand);

	void playInitialTurn(std::vector<Card>& playerHand, std::vector<Card>& dealerHand);
	void playPlayerTurn(std::vector<Card>& playerHand);
	void playDealerTurn(std::vector<Card>& dealerHand);

public:
    void play() override;
};

#endif // BLACKJACK_H