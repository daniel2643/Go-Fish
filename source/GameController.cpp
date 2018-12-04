//
//  GameController.cpp
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 08/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//

//------------------------------------------------------------------------------------------//
//                            ****Go Fish****                                               //
//  Extra Functionality: Save and Load Game                                                 //
//                       Making different sets worth more points                            //
//                       ('A' for 5 points, 'J','Q','K' for 3 points, others for 1 point)   //
//                       Pending game(to make it more slower) to make it more humanrized.   //
//------------------------------------------------------------------------------------------//

#include "GameController.h"
#include "UtilityFunctions.h"
#include <unistd.h>

Deck GameController::s_d = Deck();
Player GameController::s_p1 = Player();
Player GameController::s_p2 = Player();
int GameController::s_run_pointer = 0;
int GameController::s_p1_set = 0;
int GameController::s_p2_set = 0;
int GameController::s_p1_scores = 0;
int GameController::s_p2_scores = 0;
bool GameController::saved = false;

GameController::GameController(){
    setup();
}

void GameController::setup(){
    
}

void GameController::play(){
    if (saved)
        // Load Game
        loadGame();
        
    else{
        //--------------------------------------------------------------------------//
        //                                                                          //
        //                          Initialization Game                             //
        //                                                                          //
        //--------------------------------------------------------------------------//
        
        // Instantiate a new card deck
        d.shuffle();
        displayDeck(d);
        
        // Instantiate players
        p1 = Player(getUserInput("Please enter player name: "));
        p2 = Player("Computer");
        
        // Deal 7 cards for each player
        for (int i = 0; i<7; i++){
            p1.addCard(d.draw());
            p2.addCard(d.draw());
        }
        
        // *Display
        cout << endl;
        //displayHandCard(p1);
        displayHandCard(p2);
        cout << "\n\n\n\n";
        //displayDeck(d);
    }
    
    
    
    //---------------------------------------------------------------------------//
    //                                                                           //
    //                             Start Game                                    //
    //                                                                           //
    //---------------------------------------------------------------------------//
    
    // Running Game
    while (!exit && (p1_set+p2_set) < 13){
        // Player1 Ask For Card
        if (run_pointer % 2 == 0){
            userTurn();
        }
        // Computer Ask For Card
        else if (run_pointer % 2 == 1){
            computerTurn();
        }
        
        run_pointer ++;
    }
    
    // Judge Game
    if ((p1_set+p2_set) < 13){
        // Save Game
        saveGame();
    }
    else if (p1_scores > p2_scores){
        cout << "\n\n\n\nYOU WIN!!!\n\n" << endl;
        displayScoreBoard();
    }
    else if (p1_scores == p2_scores){
        cout << "\n\n\n\nDEUCE\n\n" << endl;
        displayScoreBoard();
    }
    else{
        cout << "\n\n\n\nYOU LOSE~\n\n" << endl;
        displayScoreBoard();
    }
        
    
}

// Functions
/*
 *
 *
 *This Function implements running the user's turn to operate cards.
 *
 *
 */
void GameController::userTurn(){
    int count;
    int card_value;
    char tmp_value;
    bool ok = false;
    Card c;
    vector<Card> tmp;
    
    
    while (!ok){
        displayHandCard(p1);
        usleep(1000000);
        tmp_value = getUserInputChar("What rank do you want to ask "+ p2.getName() + " for? (X for 10)(q/e for quit)");
        if (tmp_value == 'q' || tmp_value == 'e')
            exit = true;
        card_value = getUserInputValue(tmp_value);
        if (!p1.isCardIn(card_value) && !(card_value == 0))
            cout << "ERROR: Please enter the value from your hand!" << endl << endl;
        else
            ok = true;
    }
    
    
    if (p2.isCardIn(card_value)){
        tmp = p2.removePassCard(card_value);
        for (int i=0; i<tmp.size(); i++){
            p1.addCard(tmp[i]);
        }
        if (p2.isEmpty()){
            count = 0;
            while (count<7 && count<d.getCardsNum()){
                p2.addCard(d.draw());
                count++;
            }
        }
        
        c = Card(1, card_value);
        cout << p2.getName()<< " give you " << tmp.size() << " " << c.getValueAsString() << endl;
        usleep(2000000);
        
        if (p1.isFull(card_value)){
            p1_set++;
            if (card_value == 1)
                p1_scores+=5;
            else if (card_value == 11 || card_value == 12 || card_value == 13)
                p1_scores+=3;
            else
                p1_scores+=1;
            cout << p1.getName() << " takes a trick of " << c.getValueAsString() << endl << endl << endl;
            if (p1.isEmpty()){
                count = 0;
                while (count<7 && count<d.getCardsNum()){
                    p1.addCard(d.draw());
                    count++;
                }
            }
        }
        else
            cout << endl << endl;
        usleep(2000000);
        run_pointer--;
    }
    else if (!(card_value==0)){
        cout << p2.getName() << ": 'Go Fish!'" << endl;
        usleep(2000000);
        c = d.draw();
        cout << "You draw a " << c.getSuitAsString() << c.getValueAsString() << "." << endl << endl << endl;
        usleep(1000000);
        if (c.getValue() == card_value)
            run_pointer--;
        p1.addCard(c);
    }
}

/*
 *
 *
 *This Function implements running the computer's turn to operate cards.
 *
 *
 */
void GameController::computerTurn(){
    int count;
    int card_value;
    Card c;
    vector<Card> tmp;
    
    displayHandCard(p1);
    usleep(1500000);
    
    card_value = p2.getHandCards()[rand() % (p2.getHandCards().size())].getValue();
    c = Card(1, card_value);
    cout << p2.getName() << ": 'Do you have rank " << c.getValueAsString() << "?'" << endl;
    
    if (p1.isCardIn(card_value)){
        tmp = p1.removePassCard(card_value);
        for (int i=0; i<tmp.size(); i++){
            p2.addCard(tmp[i]);
        }
        if (p1.isEmpty()){
            count = 0;
            while (count<7 && count<d.getCardsNum()){
                p1.addCard(d.draw());
                count++;
            }
        }
        
        cout << "You give " << p2.getName() << " " << tmp.size() << " " << c.getValueAsString() << endl;
        usleep(3000000);
        if (p2.isFull(card_value)){
            p2_set++;
            if (card_value == 1)
                p2_scores+=5;
            else if (card_value == 11 || card_value == 12 || card_value == 13)
                p2_scores+=3;
            else
                p2_scores+=1;
            cout << p2.getName() << " takes a trick of " << c.getValueAsString() << endl << endl << endl;
            if (p2.isEmpty()){
                count = 0;
                while (count<7 && count<d.getCardsNum()){
                    p2.addCard(d.draw());
                    count++;
                }
            }
        }
        else
            cout << endl << endl;
        usleep(3000000);
        run_pointer--;
    }
    else{
        cout << p1.getName() << ": 'Go Fish!'" << endl << endl << endl;
        usleep(3000000);
        c = d.draw();
        //cout << p2.getName() << " draw a " << c.getSuitAsString() << c.getValueAsString() << "." << endl << endl << endl;
        usleep(1500000);
        if (c.getValue() == card_value)
            run_pointer--;
        p2.addCard(c);
        
        
    }
}

int GameController::getUserInputValue(char rep_card){
    bool is_valid_value = false;
    int card_value;
    while (!is_valid_value){
        switch (rep_card){
            case '2':
                card_value = 2;
                is_valid_value = true;
                break;
            case '3':
                card_value = 3;
                is_valid_value = true;
                break;
            case '4':
                card_value = 4;
                is_valid_value = true;
                break;
            case '5':
                card_value = 5;
                is_valid_value = true;
                break;
            case '6':
                card_value = 6;
                is_valid_value = true;
                break;
            case '7':
                card_value = 7;
                is_valid_value = true;
                break;
            case '8':
                card_value = 8;
                is_valid_value = true;
                break;
            case '9':
                card_value = 9;
                is_valid_value = true;
                break;
            case 'X':
                card_value = 10;
                is_valid_value = true;
                break;
            case 'J':
                card_value = 11;
                is_valid_value = true;
                break;
            case 'Q':
                card_value = 12;
                is_valid_value = true;
                break;
            case 'K':
                card_value = 13;
                is_valid_value = true;
                break;
            case 'A':
                card_value = 1;
                is_valid_value = true;
                break;
            case 'e':
                card_value = 0;
                is_valid_value = true;
                break;
            case 'q':
                card_value = 0;
                is_valid_value = true;
                break;
            default:
                cout << "ERROR: Please enter a valid card value!" << endl;
                rep_card = getUserInputChar("What rank do you want to ask for? (X for 10)(q/e for quit)");
        }
    }
    return card_value;
}

void GameController::loadGame(){
    if (getUserInputChar("Do you want to load previous game?(Y for yes)") == 'Y'){
        d = s_d;
        p1 = s_p1;
        p2 = s_p2;
        p1_set = s_p1_set;
        p2_set = s_p2_set;
        p1_scores = s_p1_scores;
        p2_scores = s_p2_scores;
        run_pointer = s_run_pointer;
    }
    cout << "\n\n\n\nGAME LOADED SUCCESSFULLY\n\n" << endl;
}

void GameController::saveGame(){
    if (getUserInputChar("Do you want to save game? (Y for save)") =='Y'){
        s_d = d;
        s_p1 = p1;
        s_p2 = p2;
        s_run_pointer = run_pointer-1;
        s_p1_set = p1_set;
        s_p2_set = p2_set;
        s_p1_scores = p1_scores;
        s_p2_scores = p2_scores;
        saved = true;
        
    }
    cout << "\n\n\n\nGAME SAVED SUCCESSFULLY\n\n" << endl;
}

// Display Functions
void GameController::displayHandCard(Player p){
    cout << p.toString();
}

void GameController::displayDeck(Deck d){
    cout << d.toString() << endl;
}

void GameController::displayScoreBoard(){
    cout << "Score Board: " << endl;
    cout << "\t" << p1.getName() << ">>" << p1_scores << " points" << endl;
    cout << "\t" << p2.getName() << ">>" << p2_scores << " points" << endl;
}


