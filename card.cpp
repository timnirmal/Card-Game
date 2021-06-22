//
// Created by Tim Nirmal

#include "card.h"

#include <iostream>
#include <io.h>
#include <time.h>
#include <vector>

using namespace std;


void card::display_card() {
    _setmode(_fileno(stdout), 0x00020000);  //For print _O_U16TEXT
    //Show value first
    if((val>=2)&&(val<=10)){
        wcout<<val;
    }
    else{
        switch (val) {
            case 11: wcout<<"J"; break;
            case 12: wcout<<"Q"; break;
            case 13: wcout<<"K"; break;
            case 1: wcout<<"A"; break;
        }
    }

    //Printing suit
    switch (s) {
        case 0: wprintf(L"\u2663"); break;
        case 1: wprintf(L"\u2665"); break;
        case 2: wprintf(L"\u2660"); break;
        case 3: wprintf(L"\u2666"); break;
    }
}

void card::setValue(int v, suit st) {
    val = v;
    s = st;
}

int card::getValue() {
    return val;
}

suit card::getSuit() {
    return s;
}


void card::randomize(card &card) {
    int R_val;
    suit R_suit;

    srand(rand() % 2000 + 1 * time(0));
    R_val = (rand() % 13 + 1);  // assign it a numeric value (2 - 14)

    for(auto &i : used_cards){
        if(i!=R_val){
            break;
        }
    }

    int i = (rand() % 4);
    switch (i)                // and a suit.
    {
        case 0: R_suit = clubs;     break;
        case 1: R_suit = heart;   break;
        case 2: R_suit = spades;     break;
        case 3: R_suit = diamond;    break;
    }


    card.setValue(R_val,R_suit);
}

void card::getCard(card &card){

    string input;   //To input method
    int value;      //To input value
    suit U_suit;    //To input suit

    switch (count_cards) {
        case 1:
            wcout << "Enter the Value & Suit of First card : ";
            break;
        case 2:
            wcout << "Enter the Value & Suit of Second card : ";
            break;
        case 3:
            wcout << "Enter the Value & Suit of Third card : ";
            break;
        case 4:
            wcout << "Enter the Value & Suit of Fourth card : ";
            break;
        case 5:
            wcout << "Enter the Value & Suit of Fifth card : ";
            break;
    }
    cin >> value;
    cin >> input;

    //Checking if input is valid and assign suit
    if (input == "0" || input == "Clubs" || input == "Club" || input == "clubs" || input == "club" ||
        input == "c" || input == "C") {
        U_suit = clubs;
        count_cards++;
    } else if (input == "1" || input == "Hearts" || input == "Heart" || input == "hearts" || input == "heart" ||
               input == "H" || input == "h") {
        U_suit = heart;
        count_cards++;
    } else if (input == "2" || input == "Spades" || input == "Spade" || input == "spades" || input == "spade" ||
               input == "S" || input == "s") {
        U_suit = spades;
        count_cards++;
    } else if (input == "3" || input == "Diamonds" || input == "Diamond" || input == "diamonds" ||
               input == "diamond" || input == "D" || input == "d") {
        U_suit = diamond;
        count_cards++;
    } else {
        wcout << "Wrong input... TRY AGAIN.....\n";
        system("cls");
        //getCard(card);
    }

    //Set values for class object
    card.setValue(value, U_suit);
}

void card::swap(int n, int m){
    int temp;
    temp = used_cards[n];
    used_cards[n]=used_cards[m];
    used_cards[m]=temp;
}

void card::display(int n, card cards[]){
    for(int i=0; i<5;i++){
        int card_out_val = n/10;
        int card_out_suit = n-((n/10)*10);

        if(cards[i].getValue()==card_out_val && cards[i].getSuit()==card_out_suit){
            cards[i].display_card();
        }
    }
}
