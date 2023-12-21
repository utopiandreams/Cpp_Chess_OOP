#include "ChessConsole.h"
#include "ChessPieces/ChessPiece.h"
#include <iostream>

ChessPiece* ChessConsole::selectPiece(){
    using namespace std;
    ChessPiece* selected = nullptr;

    if(isBlackTurn) cout << "Turn : Black" << endl;
    else cout << "Turn : White" << endl;
    cout << "Select Piece ==> ";
    
    while(selected == nullptr){
        char x; unsigned int y;
        cin >> x >> y;
        ChessPiece* p = board.getPiece(x-'A', y-1);

        // 턴에 맞지 않은 기물을 고른 경우
        if(p->Team != isBlackTurn) {
            cout << "Select Piece of ";
            if(isBlackTurn) cout << "Black Team";
            else cout << "White Team" << endl;
        } else {
            selected = p;
            p = 0;
        }
    }
    cout << "== selected Piece ==" << endl;
    selected->printInfo();
    cout << "====================" << endl;
    return selected;
};