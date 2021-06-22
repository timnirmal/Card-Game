#include <iostream>
#include <io.h>
#include <random>
#include <algorithm>
#include <stdio.h>
#include <conio.h>
#include "windows.h"
#include "Magician.h"
#include "card.h"

using namespace std;

struct sort_val{    //Use for sorting cards by assigning a index to value
    int index;
    int value;
};

Magician::Magician() {
    _setmode(_fileno(stdout), 0x00020000);  //For print _O_U16TEXT
    //so wcout is need to be used instead of wcout

    bool flag=false;    //Mark the end of the loop

    card cards[5];
    int hops = 0;
    suit hidden_card_suit;
    int hidden_card_value;
    int count=0;

    while (true) {
        if (flag == true) { break; }
        wcout << "You can use both Symbol and Name to input the method of suit\n";
        wcout << L"Suit : 0 for \u2663,  1 for \u2665,  2 for \u2660,  3 for \u2666\n";
        wcout << "Clubs(C), Hearts(H), Spades(S), Diamonds(D)\n" << endl;
        wcout << "Enter values as below for Entering values\n";
        wcout << " A 2 3 4 5 6 7 8 9 10 J Q K\n"
                 " 1 2 3 4 5 6 7 8 9 10 11 12 13\n\n";

        string input;   //To input method
        int value;

        for (int i = 1; i < 5; i++) {
            switch (i) {
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
            }
            cin >> value;
            cin >> input;

            if (input == "0" || input == "Clubs" || input == "Club" || input == "clubs" || input == "club" ||
                input == "c" || input == "C") {
                cards[i].setValue(value, clubs);
            } else if (input == "1" || input == "Hearts" || input == "Heart" || input == "hearts" || input == "heart" ||
                       input == "H" || input == "h") {
                cards[i].setValue(value, heart);
            } else if (input == "2" || input == "Spades" || input == "Spade" || input == "spades" || input == "spade" ||
                       input == "S" || input == "s") {
                cards[i].setValue(value, spades);
            } else if (input == "3" || input == "Diamonds" || input == "Diamond" || input == "diamonds" ||
                       input == "diamond" || input == "D" || input == "d") {
                cards[i].setValue(value, diamond);
            } else {
                wcout << "Wrong input... TRY AGAIN.....\n";
                system("cls");
            }
        }

        //Suit of Hidden card equals to 1 st card suit
        hidden_card_suit = cards[1].getSuit();

        struct sort_val s[3];
        int s_val[3];

        for (int i = 0; i < 3; i++) {
            s[i].value = cards[i + 2].getValue();
            s[i].index = i + 1;
            s_val[i] = cards[i + 2].getValue();
        }

        //Sorting S array
        if (s_val[0] > s_val[1])
            swap(s_val[0], s_val[1]);
        if (s[0].value > s[2].value)
            swap(s_val[0], s_val[2]);
        if (s[1].value > s[2].value)
            swap(s_val[1], s_val[2]);

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (s_val[j] == s[i].value) {
                    s[i].index = j + 1;
                }
            }
        }

        hops = 0;

        if (s[0].index < s[1].index && s[0].index < s[2].index && s[1].index < s[2].index)
            //( small, medium, large ) = 1
            hops = 1;
        if (s[0].index < s[2].index && s[0].index < s[1].index && s[2].index < s[1].index)
            //( small, large, medium ) = 2
            hops = 2;
        if (s[1].index < s[0].index && s[1].index < s[2].index && s[0].index < s[2].index)
            //( medium, small, large ) = 3
            hops = 3;
        if (s[1].index < s[2].index && s[1].index < s[0].index && s[2].index < s[1].index)
            //( medium, large, small ) = 4
            hops = 4;
        if (s[2].index < s[0].index && s[2].index < s[1].index && s[0].index < s[1].index)
            //( large, small, medium ) = 5
            hops = 5;
        if (s[2].index < s[1].index && s[2].index < s[0].index && s[1].index < s[0].index)
            //( large, medium, small ) = 6
            hops = 6;

        count++;
        if (hops == 0) {
            wcout << "\n\n================================================================"
                     "\nInput failed please enter Different set of Cards...\n\n";
            system("pause");
            if (count > 1) {
                system("cls");
                wcout << "Please make sure the values of the last 3 cards you enter are not equl.\n\n";
                system("pause");
            }
            system("cls");
            flag = false;
            continue;
        } else {
            flag = true;
        }

        int val_array[19] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 1, 2, 3, 4, 5, 6};

        for (int i = 0; i < 13; i++) {
            if (val_array[i] == cards[1].getValue()) {
                hidden_card_value = val_array[i + hops];
            }
        }

        wcout << "\n\nHidden Card : ";
        cards[0].setValue(hidden_card_value, hidden_card_suit);
        cards[0].display_card();
        wcout << endl;
    }

}

