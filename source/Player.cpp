//
//  Player.cpp
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 07/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#include "Player.h"


int Player::player_count = 0;

//Constructors
Player::Player(){
    name = "Player" + to_string(player_count+1);
    player_count++;
}

Player::Player(string init_name){
    name = init_name;
    player_count++;
}

//Destructor
Player::~Player(){
    player_count--;
}


//Mutators
bool Player::setName(string new_name){
    bool is_valid = false;
    name = new_name;
    is_valid = true;
    return is_valid;
    
}

void Player::addCard(Card new_card){
    bool is_insert = false;
    int n = hand_cards.size();
    int i = 0;
    if (n==0){
        hand_cards.push_back(new_card);
        is_insert = true;
    }
    while (n==hand_cards.size() && i<n){
        if (hand_cards[i].getValue() > new_card.getValue() || (hand_cards[i].getValue() == new_card.getValue() && hand_cards[i].getSuit() >= new_card.getSuit())){
            hand_cards.insert(hand_cards.begin()+i, new_card);
            is_insert = true;
        }
        i++;
    }
    if (!is_insert)
        hand_cards.push_back(new_card);
}


//toString method
string Player::toString(){
    stringstream ss;
    ss << name << " ***** Cards in Hand:" << endl;
    for (int i = 0; i<hand_cards.size(); i++){
        ss << hand_cards[i].toString() << "  ";
    }
    ss << endl;
    return ss.str();
}

//Other methods
void Player::sortHandCards(){
    int n = hand_cards.size();
    for (int i=1; i<n; i++){
        int j = i;
        while (j>0 && ((hand_cards[j].getValue()<hand_cards[j-1].getValue()) || (hand_cards[j].getValue() == hand_cards[j-1].getValue() && hand_cards[j].getSuit()<hand_cards[j-1].getSuit()))){
            hand_cards[j], hand_cards[j-1] = hand_cards[j-1], hand_cards[j];
            j--;
        }
    }
}

bool Player::isCardIn(int new_card_value){
    bool in = false;
    int n = getHandCards().size();
    for (int i=0; i<n; i++){
        if(new_card_value==getHandCards()[i].getValue()){
            in = true;
            break;
        }
    }
    return in;
}

bool Player::isFull(int card_value){
    bool full = false;
    int count = 0;
    for (int i=0; i<getHandCards().size(); i++){
        if (getHandCards()[i].getValue()==card_value)
            count++;
    }
    if (count==4)
        full = true;
    return full;
}

bool Player::isEmpty(){
    bool empty = false;
    if (getHandCards().size() == 0)
        empty = true;
    return empty;
}

vector<Card> Player::removePassCard(int card_value){
    vector<Card> tmp;
    int i = 0;
    while(i<getHandCards().size()){
        if (getHandCards()[i].getValue() == card_value){
            tmp.push_back(getHandCards()[i]);
            hand_cards.erase(hand_cards.begin()+i);
            i--;
        }
        i++;
    }
    
    return tmp;
}

