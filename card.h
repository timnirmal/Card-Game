//
// Created by Tim Nirmal

enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

#include <vector>

using namespace std;

static vector <int> used_cards;
static vector <int> used_cards_suit;

static int count_cards =1;

#ifndef UNTITLED4_CARD_H
#define UNTITLED4_CARD_H

class card {
private:
    int val; //( A = 1, J = 11, Q = 12, K = 13)
    suit s;
public:
    //card():val(0),s(0);
    void display_card();
    void setValue(int v,suit st);
    int getValue();
    suit getSuit();

    static void randomize(card &card);
    static void swap(int n, int m);
    static void display(int n, card cards[]);
    static void getCard(card &card);
};


#endif //UNTITLED4_CARD_H
