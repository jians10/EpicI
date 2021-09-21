//
// Created by leojiang on 9/20/2021.
//

#ifndef UNTITLED1_BOARD_H
#define UNTITLED1_BOARD_H
#include <vector>
#include <iostream>

class Board {
    int Width;
    int Length;
    int Connect;

public:
    std::vector<std::vector<char>> vectorBoard;
    std::vector<std::vector<int>> myStack;
    Board(int m, int n,int k);
    void Print();
    bool isValid(int i, int j)const;
    bool CanSet(int i,int j);
    bool Put(int i, int j, char target);
    void Remove(int i, int j);
    bool CheckWinner(int i, int j,char Target);
    bool CheckWinnerHelper( int i, int j, int dirx, int diry,char Target);
    bool Regret(int userindex, int regretStep);
};


#endif //UNTITLED1_BOARD_H
