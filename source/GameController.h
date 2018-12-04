//
//  GameController.h
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 09/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

#ifndef GameController_h
#define GameController_h


#include "Player.h"

class GameController{
    
private:
    //Variables
    Deck d = Deck();
    Player p1;
    Player p2;
    int run_pointer = 0;
    int p1_set = 0;
    int p2_set = 0;
    int p1_scores = 0;
    int p2_scores = 0;
    bool exit = false;
    
    static bool saved;
    static Deck s_d;
    static Player s_p1;
    static Player s_p2;
    static int s_run_pointer;
    static int s_p1_set;
    static int s_p2_set;
    static int s_p1_scores;
    static int s_p2_scores;
    
    //Functions
    void userTurn();
    void computerTurn();
    int getUserInputValue(char r);
    void loadGame();
    void saveGame();
    
    //Display Functions
    void displayHandCard(Player p);
    void displayDeck(Deck d);
    void displayScoreBoard();
    
public:
    GameController();
    
    void setup();
    void play();
};

#endif /* GameController_h */
