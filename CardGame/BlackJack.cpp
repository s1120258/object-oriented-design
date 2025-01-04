#include "BlackJack.h"
#include <iostream>

void BlackJack::drawCard(std::vector<Card>& hand) {
	hand.push_back(deck.back());
	deck.pop_back();
}

int BlackJack::getCardValue(const Card& card) {
    if (card.rank >= Two && card.rank <= Ten) {
        return card.rank;
    } else if (card.rank >= Jack && card.rank <= King) {
        return 10;
    } else if (card.rank == Ace) {
        return 11; // or 1, depending on the game rules
    }
    return 0;
}

int BlackJack::getHandValue(const std::vector<Card>& hand) {
    int value = 0;
    int numAces = 0;
    for (const auto& card : hand) {
        if (card.rank == Ace) {
            ++numAces;
        }
        value += getCardValue(card);
    }
    while (value > 21 && numAces > 0) {
        value -= 10;
        --numAces;
    }
    return value;
}

void BlackJack::playInitialTurn(std::vector<Card>& playerHand, std::vector<Card>& dealerHand) {
	// deal two cards to player and dealer
	drawCard(playerHand);
	drawCard(dealerHand);
	drawCard(playerHand);
	drawCard(dealerHand);

	std::cout << "Player's hand value: " << getHandValue(playerHand) << std::endl;
	std::cout << "Dealer's first card value: " << getCardValue(dealerHand[0]) << std::endl;
}

void BlackJack::playPlayerTurn(std::vector<Card>& playerHand) {
    char choice;
    do {
        std::cout << "Do you want to draw another card? (y/n): ";
        std::cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            drawCard(playerHand);
            std::cout << "Player's hand value: " << getHandValue(playerHand) << std::endl;
            if (getHandValue(playerHand) > 21) {
                std::cout << "Player busts! Dealer wins." << std::endl;
                return;
            }
        }
    } while (choice == 'y' || choice == 'Y');
}

void BlackJack::playDealerTurn(std::vector<Card>& dealerHand) {
    // dealer draws until hand value is 17 or more
    while (getHandValue(dealerHand) < 17) {
        drawCard(dealerHand);
    }
}

void BlackJack::play() {
    std::vector<Card> playerHand;
    std::vector<Card> dealerHand;

    playInitialTurn(playerHand, dealerHand);
	playPlayerTurn(playerHand);
	playDealerTurn(dealerHand);

    int playerValue = getHandValue(playerHand);
    int dealerValue = getHandValue(dealerHand);
    std::cout << "Dealer's hand value: " << dealerValue << std::endl;

    if (dealerValue > 21 || playerValue > dealerValue) {
        std::cout << "Player wins!" << std::endl;
    }
    else if (playerValue < dealerValue) {
        std::cout << "Dealer wins!" << std::endl;
    }
    else {
        std::cout << "It's a tie!" << std::endl;
    }
}
