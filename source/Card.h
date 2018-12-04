//
//  Card.h
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 07/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Card_h
#define Card_h

#include <iostream>
#include <string>
#include <sstream>
#include <ctime>
#include <vector>

using namespace std;

class Card{
private:
    int suit;
    int value;
    static string suit_representor[];
    static string value_representor[];
    static int card_count;

    
    
public:
    //constructers
    Card();
    Card(int init_suit, int init_value);
    
    //destructor
    ~Card();
    
    //accessor
    int getSuit(){return suit;}
    int getValue(){return value;}
    
    //quasi-accessor
    string getSuitAsString(){return suit_representor[suit];}
    string getValueAsString(){return value_representor[value];}
    
    //mutators
    bool setSuit(int new_suit);
    bool setValue(int new_value);
    
    
    //toString method
    string toString();
    
    
    //other methods
    string repValue();
    
};

#endif /* Card_h */
