#include "ChessConsole.h"
#include <iostream>

int ChessConsole::run(void){
    while(true){
        graphics.Render();
        ChessPiece* selectedPiece = selectPiece();
        this->movePiece(selectedPiece);
        isBlackTurn = !isBlackTurn;
        if(board.winner != -1) gameOver();
    }
    return 0;
}