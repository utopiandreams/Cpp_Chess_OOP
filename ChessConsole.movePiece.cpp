#include "ChessConsole.h"
#include "ChessPieces/ChessPiece.h"
#include <iostream>

ChessConsole::ChessConsole():board(true), graphics(&board){}

void ChessConsole::movePiece(ChessPiece* selectedPiece){
    using namespace std;
    while(true){
        cout << "Move Piece ==> ";
        char x; unsigned int y;
        cin >> x >> y;
        if(selectedPiece->move(x-'A', y-1, &(this->board))) return;
        cout << "invalid move" << endl;
    }

};

