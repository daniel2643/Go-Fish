//
//  Card.cpp
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 07/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Card.h"

string Card::suit_representor[] = {"","♣", "♦", "♥", "♠"};
string Card::value_representor[] = {"", "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
int Card::card_count = 0;

//Constructors
Card::Card(){
    suit = rand() % 4 + 1;
    value = rand() % 13 +1;
    card_count++;
}

Card::Card(int init_suit, int init_value){
    if (!setSuit(init_suit) || !setValue(init_value))
        throw invalid_argument("wrong initialisation");
}

//Destructor
Card::~Card(){
    card_count--;
}


//Mutators
bool Card::setSuit(int new_suit){
    bool ret_val = false;
    if (new_suit>0 && new_suit<5 && new_suit%1==0){
        suit = new_suit;
        ret_val = true;
    }
    return ret_val;
}

bool Card::setValue(int new_value){
    bool ret_val = false;
    if (new_value>0 && new_value<14 && new_value%1==0){
        value = new_value;
        ret_val = true;
    }
    return ret_val;
}


//toString method
string Card::toString(){
    stringstream ss;
    ss << Card::getSuitAsString() << "" << Card::getValueAsString() << "";
    return ss.str();
}



//Other methods


