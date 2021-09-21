//
// Created by leojiang on 9/20/2021.
//

#ifndef UNTITLED1_TICTACTOE_H
#define UNTITLED1_TICTACTOE_H
#include <iostream>
#include <string>
#include <vector>
#include<stack>
#include "Board.h"

using namespace std;

class TicTacToe {

    const int ROW = 3;
    const int COL = 3;
    const int K=3;
    const int maxX= ROW-1;
    const int maxY= COL-1;
    Board board;
    int row;
    int col;
    int Step=0;
    std::vector<vector<int>> myStack{};
    int winner = 0;
    bool gameover = false;
    string playername1;
    string playername2;




public:
        TicTacToe(const int m, const int n, const int k);
        ~TicTacToe() {}
        void SetPlayerName();
        void MoveX();
        void MoveO();
        bool Regret(int userindex);
};

#endif //UNTITLED1_TICTACTOE_H
