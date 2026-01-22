#include "Deck.hpp"
#include <ostream> //for the operator<<
using namespace std;
ostream &operator<<(ostream &os, const Card &card) {
  os << card.theValue;
  switch (card.theSuit) {
  case Spades:
    os << "\u2660";
    break;
  case Hearts:
    os << "\u2665";
    break;
  case Clubs:
    os << "\u2663";
    break;
  default:
    os << "\u2666";
  }
  return os; // need this at the end
}
// Implementations of the Deck methods

Deck::Deck() {
  this->size = 52;
  this->deck = new Card[52];
  char values[] = {'A', 'K', 'J', 'T', '9', '8', '7', '6', '5', '4', '3', '2'};
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 13; j++) {
      deck[i].theSuit = (Suit)i;
      deck[j].theValue = values[j];
    }
  }
}

Deck::~Deck() { delete[] this->deck; }

void Deck::printDeck() {
  int count = 0;
  while (count < this->size) {
    cout << deck[count];
  }
  count++;
  if (count % 13 == 0) {
    cout << endl;
  }
}
