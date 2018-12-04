//
//  Deck.h
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 07/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef Deck_h
#define Deck_h

#include "Card.h"

using namespace std;

class Deck{
private:
    Card deck_list[53];
    static int cards_num;
    static vector<Card> n;
    
    
public:
    //constructers
    Deck();
    
    //accessor
    int getCardsNum(){return cards_num;}
    
    
    //mutators
    
    
    //toString method
    string toString();
    
    
    //other methods
    void fill();
    Card draw();
    void shuffle();
    

};


#endif /* Deck_h */
