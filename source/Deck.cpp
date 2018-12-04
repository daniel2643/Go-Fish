//
//  Deck.cpp
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 07/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Deck.h"

int Deck::cards_num = 0;
vector<Card> n;

//Constructors
Deck::Deck(){
    fill();
}


//Mutators


//toString method
string Deck::toString(){
    stringstream ss;
    for (int i=cards_num; i>=1; i--){
        ss << "Card" << cards_num+1-i << ".\t" << deck_list[i].toString() << endl;
    }
    return ss.str();
}


//Other methods
void Deck::fill(){
    Card c;
    
    for (int suit = 1; suit <= 4; suit++)
        for (int value = 1; value <= 13; value++){
            c = Card(suit, value);
            deck_list[(suit - 1) * 13 + value] = c;
        }
    
    cards_num = 52;
}

Card Deck::draw(){
    Card ret_val;
    if (cards_num>0){
        ret_val = deck_list[cards_num];
        cards_num--;
    }
    return ret_val;
}

void Deck::shuffle(){
    int a, b;
    Card tmp;
    
    for (int i = 1; i <= 10000; i++){
        a = 1 + (rand()% 52);
        b = 1 + (rand()%  52);
        
        tmp = deck_list[a];
        deck_list[a] = deck_list[b];
        deck_list[b] = tmp;
    }
}




