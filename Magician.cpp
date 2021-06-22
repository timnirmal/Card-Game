//
// Created by timni on 6/23/2021.
//

#include "card.h"
#include "Magician.h"


#include <iostream>
#include <io.h>
#include <vector>
#include <algorithm>

using namespace std;

Magician::Magician() {
    _setmode(_fileno(stdout), 0x00020000);  //For print _O_U16TEXT
    //so wcout is need to be used instead of wcout

    //Create 5 randoms cards using array
    card cards[5];

    bool flag = 0;       //Used for end of loop

    int count_unique=0; //Counting number of Unique cards in set

    string mod;     //To take the mod
    bool mark_mod;  //To Mark the mod is Random or Manual

    wcout << "There are two mods in this .\n";
    wcout << "You can either select random generating mode or you can enter data manually.\n";
    wcout << "\ta. Random (A)\n";
    wcout << "\ta. Manual (User Entry) (B)\n";

    wcout<<"Enter mod : ";
    cin>>mod;
    if (mod == "a" || mod == "A" || mod == "Random" || mod == "random" || mod == "RANDOM" || mod == "R" || mod == "r"){
        mark_mod=0;
    }
    else if (mod == "b" || mod == "B" || mod == "Manual" || mod == "manual" || mod == "MANUAL" || mod == "User" || mod == "user" || mod == "USER" || mod == "M" || mod == "m"){
        mark_mod=1;
    }
    else {  //Make default as Manual since that is the aim of this practical
        wcout<< "Your input is wrong...\n\n";
        wcout<< "Proceeding manual mode....\n";
        mark_mod =1;
    }

    //Instruction before manual mode
    if (mark_mod==1){
        wcout << "You can use both Symbol and Name to input the method of suit\n";
        wcout << L"Suit : 0 for \u2663,  1 for \u2665,  2 for \u2660,  3 for \u2666\n";
        wcout << "Clubs(C), Hearts(H), Spades(S), Diamonds(D)\n" << endl;
        wcout << "Enter values as below for Entering values\n";
        wcout << " A 2 3 4 5 6 7 8 9 10 J Q K\n"
                 " 1 2 3 4 5 6 7 8 9 10 11 12 13\n\n";

        wcout<< "Example : \n";
        wcout<< L"10\u2665 9\u2666 3\u2665 Q\u2660 J\u2663 as 10 1 9 3 3 1 12 2 11 0\n\n";
    }

    //Do until unique card set found
    while (true) {
        //Loop break condition
        if(count_unique==5){
            flag=true;
            break;
        }
        else{
            count_unique=0;
            used_cards.clear();
            for (int k = 0; k < 5; k++) {
                //make 5 random objects

                //Random Algorithm
                if(mark_mod == 0) {
                    card::randomize(cards[k]);
                }

                //Manual Mode
                if(mark_mod == 1) {
                    card::getCard(cards[k]);
                }

                cout<<endl<<endl<<"Im out"<<endl;

                int x = cards[k].getValue();
                int y = cards[k].getSuit();
                int calc = x * 10 + y;
                used_cards.push_back(calc);

                sort(used_cards.begin(), used_cards.end());     //Sort before counting unique values
                count_unique = distance(used_cards.begin(), unique(used_cards.begin(), used_cards.end()));
                used_cards.resize(count_unique);
            }
        }
    }


    //Now we have created 5 unique cards

    //=====Now let's choose hidden card
    //====1. pick two cards with equal suit

    used_cards.clear();

    for(int i =0; i<5;i++){
        int x = cards[i].getValue();
        int y = cards[i].getSuit();
        int calc = x * 10 + y;
        used_cards.push_back(calc);
        used_cards_suit.push_back(y);
    }

    vector <int> choosen;

    for(int i =0; i<4;i++){
        for(int j=i+1; j<5;j++){
            if(used_cards_suit[i]==used_cards_suit[j]){
                choosen.push_back(used_cards[i]);
                choosen.push_back(used_cards[j]);
                break;
            }
        }
    }
    choosen.resize(2);

    //====2.Now we have choosed two cards with same values
    //===If more than 2 sets availble this method only get one set

    //===Resize used_cards for processing non choosen cards.
    vector<int>::iterator new_end;
    new_end = remove(used_cards.begin(),used_cards.end(),choosen[0]);
    new_end = remove(used_cards.begin(),used_cards.end(),choosen[1]);
    used_cards.resize(3);

    //====3.Now Start from first card and check whether if it =< 6 hops. Else pick second card as hidden card
    sort(choosen.begin(),choosen.end());
    int diff = ((choosen[0]/10)*10)-((choosen[1]/10)*10);
    int hidden_card;
    int non_hidden_card;

    if(diff>=-6 && diff<0){
        hidden_card = choosen[1];
        non_hidden_card = choosen[0];
    }else{
        hidden_card = choosen[0];
        non_hidden_card = choosen[1];
    }

    diff = abs(diff/10);

    if(diff>6){
        diff = 13 - diff;
    }

    //Now Used_cards represent the remaining three cards
    //Sort them out
    sort(used_cards.begin(),used_cards.end());

    //Ordering rest of the numbers
    int temp=0;
    switch (diff){
        case 1:
            //( small, medium, large ) = 1
            //already in order
            break;
        case 2:
            //0 1 2
            //( small, large, medium ) = 2
            card::swap(1,2);
            break;
        case 3:
            //( medium, small, large ) = 3
            card::swap(0,1);
            break;
        case 4:
            //( medium, large, small ) = 4
            card::swap(0,2);
            card::swap(0,1);
            break;
        case 5:
            //( large, small, medium ) = 5
            card::swap(0,2);
            card::swap(1,2);
            break;
        case 6:
            //( large, medium, small ) = 6
            card::swap(0,2);
            break;
    }

    wcout<<"\n\nCards : ";
    card::display(non_hidden_card, cards); wcout<<" ";
    card::display(used_cards[0], cards); wcout<<" ";
    card::display(used_cards[1], cards); wcout<<" ";
    card::display(used_cards[2],cards); wcout<<" ";

}

//Assistent sort them out ✔
//clubs (♣), diamonds (♦), hearts (♥), and spades (♠) ✔
//Create 5 randoms cards ✔
//Chose hidden cards
//  select two card with same suit
//  Use circular array
//  Start from first card and check whether if it =< 6 hops
//  else pick second card as hidden card
//  sort other three cards against the 2*(clubs+1*10);
// A♣ A♥ A♠ A♦ 2♣ 2♥ 2♠ 2♦ . . . Q♣ Q♥ Q♠ Q♦ K♣ K♥ K♠ K♦
// ( small, medium, large ) = 1 (hopes for clockwise)
// ( small, large, medium ) = 2
// ( medium, small, large ) = 3
// ( medium, large, small ) = 4
// ( large, small, medium ) = 5
// ( large, medium, small ) = 6
