//
// Created by leojiang on 9/20/2021.
//

#include "Board.h"


Board:: Board(int m, int n,int k):
vectorBoard(std::vector<std::vector<char>>(m,std::vector<char>(n,' '))),
Width(n),
Length(m),
Connect(k)
{
    std::cout<<"BoardCreated"<<std::endl;
}

void Board:: Print(){

    for(int i=0;i<Length;i++){
            std::cout <<"|";
            for(int j=0;j<Width;j++){
                std::cout<<vectorBoard[i][j]<<"|";
            }
            std::cout << std::endl;
    }
}

bool Board::isValid(int i, int j) const
{
    return i<=(vectorBoard.size()-1) && i>=0&& j<=(vectorBoard.size()-1)&& j>=0;
}
bool Board::CanSet(int i, int j)
{
    if (isValid(i,j)){
        return vectorBoard[i][j]==' ';
    }
    return false;
}
bool Board:: Put(int i, int j,char Target){
    if(CanSet(i,j)){
        vectorBoard[i][j]= Target;
        int userindex=0;
        if(Target=='X'){
            userindex=1;
        }
        else{
            userindex=2;
        }
        myStack.push_back({userindex, i,j});
        return true;
    }
    return false;
}




bool Board:: CheckWinner(int i, int j,char Target){
    return  CheckWinnerHelper(i,j,1,1,Target)||
            CheckWinnerHelper(i,j,1,0,Target)||
            CheckWinnerHelper(i,j,0,1,Target)||
            CheckWinnerHelper(i,j,-1,1,Target);
}

bool Board::CheckWinnerHelper(int i, int j, int dirx, int diry,char Target) {
    int count=0;
    while(true){
        if(!isValid(i+dirx,j+diry)){
            break;
        }
        if(vectorBoard[i+dirx][j+diry]!= Target){
            break;
        }
        count++;
        if(count>=Connect){
            return true;
        }
    }
    while(true){
        if(!isValid(i-dirx,j-diry)){
            break;
        }
        if(vectorBoard[i-dirx][j-diry]!= Target){
            break;
        }
        count++;
        if(count>=Connect){
            return true;
        }
    }
    return false;

}

void Board:: Remove(int i, int j) {
    if(isValid(i,j)){
        vectorBoard[i][j]=' ';
    }
}
bool Board:: Regret(int userindex, int regretStep){
    if(regretStep>0){
        std::vector<int> a= myStack.back();
        if(a[0]==userindex){
            regretStep--;
        }
        Remove(a[1],a[2]);
    }
}