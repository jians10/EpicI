#include "TicTacToe.h"

TicTacToe::TicTacToe(const int m, const int n, const int k)
        : ROW(m),
          COL(n),
          K(k),board(Board(m,n,k)),
          Step(0){
        board.Print();
}
void TicTacToe::MoveX()
{
    bool MyTurn = true;
   // while(MyTurn) {
        cout << "Now" + playername1 + ". It is your turn" << endl;
        cout << "Row:";
        cin >> row;
        cout << endl << "Col:";
        cin >> col;

        while (!board.Put(row, col, 'X')) {
            cout << "Please Enter Valid Row and Col Value !!" << endl;
            cin >> row;
            cout << endl << "Col:";
            cin >> col;
        }
        board.Print();

        if (board.CheckWinner(row, col, 'X')) {
            cout << playername1 + " win this game ";
        }
     //   MyTurn = Regret(1);
    //}
}

void TicTacToe::MoveO()
{
    bool MyTurn = true;
    //while(MyTurn) {
        cout << "Now"+ playername2+". It is your turn"<<endl;
        cout << "Row:";
        cin >> row;
        cout << endl << "Col:";
        cin >> col;
        while (!board.Put(row, col, 'O')) {
            cout << "Please Enter Valid Row and Col Value !!" << endl;
            cout << "Row:";
            cin >> row;
            cout << endl << "Col:";
            cin >> col;
        }
        board.Print();
        if (board.CheckWinner(row, col, '0')) {
            cout << playername1 + " win this game ";
        }
        //MyTurn= Regret(2);
    //}
}

void TicTacToe::SetPlayerName() {
    cout << "Player 1, enter your name:";
    cin >> playername1;
    cout << "Hello " << playername1 << ", you are X." << endl;
    cout << "Player 2, enter your name:";
    cin >> playername2;
    cout << "Hello " << playername2 << ", you are O." << endl;
}

bool TicTacToe::Regret(int userindex) {
    string ans;
    cout << "Do your want regret?[Y/N]";
    cin >> ans;
    while(!(ans.compare("Y")||ans.compare("N")||ans.compare("n")||ans.compare("y"))){
        cout << "Please input valid ans:";
        cin>> ans;
    }
    if(ans.compare("N")||ans.compare("Y")){
        return false;
    }
    else{
        return board.Regret(userindex,0);
    }
}



