//
// Created by leojiang on 9/20/2021.
//

#include <iostream>
#include <string>
#include "TicTacToe.h"

int main() {

std::cout<< "helloword"<< std::endl;
    int n=3;
    int m=3;
    int k=3;

    cout << "Welcome to the game!" << endl << endl;
    cout << "Enter M:";
    cin >> m;
    cout << "Enter N:";
    cin >> n;
    cout <<"Enter K:";
    cin >> k;
    while(k>m&&k>n){
        cout<<"plaese enter a valid K"<<endl;
    }

    TicTacToe game(m,n,k);
    game.SetPlayerName();
    game.MoveX();
    game.MoveO();
    game.MoveX();
    game.MoveO();
    game.MoveX();
    game.MoveO();

    return 0;
}
