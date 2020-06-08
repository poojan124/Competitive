from abc import ABCMeta, abstractmethod
from enum import Enum
from random import shuffle
import sys


class Suit(Enum):

    HEART = 0
    DIAMOND = 1
    CLUBS = 2
    SPADE = 3


class Card(metaclass=ABCMeta):

    def __init__(self, value, suit):
        self.value = value
        self.suit = suit
        self.is_available = True

    @property
    @abstractmethod
    def value(self):
        pass

    @value.setter
    @abstractmethod
    def value(self, other):
        pass


class BlackJackCard(Card):

    def __init__(self, value, suit):
        super(BlackJackCard, self).__init__(value, suit)

    def is_ace(self):
        return True if self._value == 1 else False

    def is_face_card(self):
        """Jack = 11, Queen = 12, King = 13"""
        return True if 10 < self._value <= 13 else False

    @property
    def value(self):
        if self.is_ace() == 1:
            return 1
        elif self.is_face_card():
            return 10
        else:
            return self._value

    @value.setter
    def value(self, new_value):
        if 1 <= new_value <= 13:
            self._value = new_value
        else:
            raise ValueError('Invalid card value: {}'.format(new_value))


class Hand(object):

    def __init__(self, cards):
        self.cards = cards

    def add_card(self, card):
        self.cards.append(card)


class BlackJackHand(Hand):

    BLACKJACK = 21

    def __init__(self, cards):
        super(BlackJackHand, self).__init__(cards)

    def score(self):
        min_over = 100
        max_under = -100
        for score in self.possible_scores():
            if self.BLACKJACK < score < min_over:
                min_over = score
            elif max_under < score <= self.BLACKJACK:
                max_under = score
        return max_under if max_under != -100 else min_over

    def possible_scores(self):
        """Return a list of possible scores, taking Aces into account."""
        scores = [0]
        for card in self.cards:
            if card.value == 1:
                ace_score_1 = [score + 1 for score in scores]
                ace_score_11 = [score + 11 for score in scores]
                scores = ace_score_1 + ace_score_11
            else:
                scores = [score + card.value for score in scores]
        return scores

    def is_burst(self):
        if self.score() > self.BLACKJACK:
            return True
        else:
            return False

class Deck(object):

    def __init__(self, cards):
        self.cards = cards
        self.deal_index = 0

    def remaining_cards(self):
        return len(self.cards) - self.deal_index

    def deal_card(self):
        try:
            card = self.cards[self.deal_index]
            card.is_available = False
            self.deal_index += 1
        except IndexError:
            return None
        return card

    def shuffle(self):
        shuffle(self.cards)


class Game(object):

    def __init__(self, cards):
        self.deck = Deck(cards)
        self.score_player = 0
        self.dealer_hand = BlackJackHand([])
        self.player_hand = BlackJackHand([])

    def check(self):

        if self.player_hand.is_burst():
            print("Player Lost!")

        while self.dealer_hand.score() < self.player_hand.score() :
            if not self.deck.remaining_cards():
                print("Game ended due to lack of cards!")
                return
            card = self.deck.deal_card()
            self.dealer_hand.add_card(card)
        
        if self.dealer_hand.is_burst():
            print("Player Won!")
        elif self.player_hand.score() == self.dealer_hand.score():
            print("Tied")
        else:
            print("Player Lost!")
    
    def draw_initial(self):
        
        if self.deck.remaining_cards():
            card = self.deck.deal_card()
            self.player_hand.add_card(card)
            print("Player got {} card".format(card.value))
        else:
            return False
        if self.deck.remaining_cards():
            card = self.deck.deal_card()
            print("Dealer got {} card".format(card.value))
            self.dealer_hand.add_card(card)
        else:
            return False
        if self.deck.remaining_cards():
            card = self.deck.deal_card()
            self.player_hand.add_card(card)
            print("Player got {} card".format(card.value))
        else:
            return False
        if self.deck.remaining_cards():
            card = self.deck.deal_card()
            self.dealer_hand.add_card(card)
            print("Dealer hidden card.")
        else:
            return False
        return True

    def play(self):
        self.deck.shuffle()
        while self.draw_initial():
            while input("Hit? Y or N : ") == "Y":
                if not self.deck.remaining_cards():
                    print("Game ended due to lack of cards!")
                    return
                card = self.deck.deal_card()
                self.player_hand.add_card(card)
                if self.player_hand.is_burst():
                    print("Player Burst! New hand.")
                    break
            self.check()

        print("Game ended")


if __name__ == "__main__":

    cards = []
    for suit in Suit:
        for value in range(1,14):
            cards.append(BlackJackCard(value, suit.value))
    
    print(len(cards))
    game = Game(cards)
    game.play()

    # deck = Deck(cards)
    # print(deck.remaining_cards())