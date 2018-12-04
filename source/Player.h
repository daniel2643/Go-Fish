//
//  Player.h
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 07/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Player_h
#define Player_h


#include "Card.h"
#include "Deck.h"

using namespace std;

class Player{
private: // instance variables
    string name;
    vector<Card> hand_cards;
    static int player_count;
    
public:
    //constructers
    Player();
    Player(string init_name);
    
    //destructor
    ~Player();
    
    //accessor
    string getName(){return name;}
    vector<Card> getHandCards(){return hand_cards;}
    
    
    //mutators
    bool setName(string new_name);
    void addCard(Card new_card);
    
    //toString method
    string toString();
    
    
    //other methods
    void sortHandCards();
    bool isCardIn(int new_card_value);
    bool isFull(int card_value);
    bool isEmpty();
    vector<Card> removePassCard(int card_value);
    
    
    
};
#endif /* Player_h */
