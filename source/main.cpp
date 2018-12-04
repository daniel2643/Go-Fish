//
//  main.cpp
//  FIT1048-AA2-28306848
//
//  Created by Daniel on 09/09/2017.
//  Copyright © 2017 Daniel. All rights reserved.
//
//  Extra Functionality: Save and Load game
//


#include "GameController.h"

int main() {
    srand(time(NULL));
    GameController game = GameController();
    game.play();
    
    //game2 is just for testing save and load game
    GameController game2 = GameController();
    game2.play();
    //system("pause");
    return 0;
}
