//
// Created by Tim Nirmal

enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3

#include <vector>

using namespace std;

#ifndef UNTITLED4_CARD_H
#define UNTITLED4_CARD_H

class card {
private:
    int val; //( A = 1, J = 11, Q = 12, K = 13)
    suit s;
public:
    //card():val(0),s(0);
    void display_card();
    void display_card_without_symbols();
    void setValue(int v,suit st);
    int getValue();
    suit getSuit();
};


#endif //UNTITLED4_CARD_H
