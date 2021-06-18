#include <iostream>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include <time.h>
#include <random>

using namespace std;

enum suit {clubs, heart, spades, diamond};
//♣0 ♥1 ♠2 ♦3
// A 2 3 4 5 6 7 8 9 10 J Q K
// 1 2 3 4 5 6 7 8 9 10 11 12 13

vector <int> used_cards_val;
int used_cards_suit[5];

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
    void randomize();
};

void card::display_card() {
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


void randomize(card &card) {
    int R_val;
    suit R_suit;

    srand(rand() % 2000 + 1 * time(0));
    R_val = (rand() % 13 + 1);  // assign it a numeric value (2 - 14)

    for(auto &i : used_cards_val){
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

int randomVal(){
    srand(rand()%2000+1*time(0));

    int array[13]={1,2,3,4,5,6,7,8,9,10,11,12,13};

    for(int j=0; j<50; j++){
        int i = rand()%13;
        wcout<<array[i]<<" ";
    }

    return 0;
}
/*
suit randomSuit(){
    srand(rand()%2000+1*time(0));

    //suit array[4]={1,2,3,4,5,6,7,8,9,10,11,12,13};

    for(int j=0; j<50; j++){
        int i = rand()%13;
       // wcout<<array[i]<<" ";
    }

    return array[0];
}*/

int main() {
    _setmode(_fileno(stdout), 0x00020000);  //For print _O_U16TEXT
    //so wcout is need to be used instead of wcout

    card c1;
    card c2;
    card c3;
    card c4;
    card c5;

    //Create 5 randoms cards
    randomize(c1);
    randomize(c2);
    randomize(c3);
    randomize(c4);
    randomize(c5);
wcout<<endl;
    //c1.display_card();wcout<<endl;
    //c2.display_card();wcout<<endl;
    //c3.display_card();wcout<<endl;
    //c4.display_card();wcout<<endl;
    //c5.display_card();wcout<<endl;

    wcout<<endl;

    card cards[5];
    //randomize(cards[0]);
//for(int j=0; j<100;j++){
    for(int i=0; i<5;i++){
        //make 5 objects
        randomize(cards[i]);
        //cards[i].display_card();
        //wcout<<endl<<cards[i].getValue()<<" "<<cards[i].getSuit()<<endl;
        //wcout<<cards[i].getValue()*(cards[i].getSuit()+1*10)<<endl;
        for(auto &used : used_cards_val){

            if(used == cards[i].getValue()*(cards[i].getSuit()+1*10)){
                wcout<<"Yes";

            }
            else{
                used_cards_val.push_back(cards[i].getValue()*(cards[i].getSuit()+1*10));
            }
        }

        /*
        if(cards[i].getValue()==cards[i+1].getValue() && cards[i].getSuit()==cards[i+1].getSuit()){
            do{
                wcout<<cards[i].getValue()<<" "<<cards[i+1].getValue()<<"  "
                <<cards[i].getSuit()<<" "<<cards[i+1].getSuit()<<endl;
                randomize(cards[i]);
            }while(cards[i].getValue()!=cards[i+1].getValue());
        }*/
    }



    cards[0].display_card();
    cards[1].display_card(); wcout<<endl;
    cards[2].display_card(); wcout<<endl;
    cards[3].display_card(); wcout<<endl;
    cards[4].display_card(); wcout<<endl;

    //cards[0].display_card(); wcout<<" ";
    //cards[1].display_card(); wcout<<" ";
    //cards[2].display_card(); wcout<<" ";
    //cards[3].display_card(); wcout<<" ";
    //cards[4].display_card(); wcout<<" ";

    wcout<<endl;
//}
    return 0;
}

//Select 5 random cards
//Assistent sort them out
//clubs (♣), diamonds (♦), hearts (♥), and spades (♠)
//Create 5 randoms cards
//Chose hidden cards
//  select two card with same suit
//  Use circular array
//  Start from first card and check whether if it =< 6 hops
//  else pick second card as hidden card
//  sort other three cards against the wcout<<2*(clubs+1*10);
// A♣ A♥ A♠ A♦ 2♣ 2♥ 2♠ 2♦ . . . Q♣ Q♥ Q♠ Q♦ K♣ K♥ K♠ K♦
// ( small, medium, large ) = 1 (hopes for clockwise)
// ( small, large, medium ) = 2
// ( medium, small, large ) = 3
// ( medium, large, small ) = 4
// ( large, small, medium ) = 5
// ( large, medium, small ) = 6






//=========== Circular array
/* // CPP program to demonstrate the use of circular
// array without using extra memory space
#include <bits/stdc++.h>
using namespace std;

// function to print circular list starting
// from given index ind.
void print(char a[], int n, int ind)
{
    // print from ind-th index to (n+i)th index.
    for (int i = ind; i < n + ind; i++)
        wcout << a[(i % n)] << " ";
}

// Driver code
int main()
{
    char a[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
    int n = sizeof(a) / sizeof(a[0]);
    print(a, n, 3);
    return 0;
}
 */