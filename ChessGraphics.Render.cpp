#include <iostream> 
#include "ChessGraphics.h"
#include "ChessBoard.h"

void ChessGraphics::Render(void) {
    using namespace std;
    const char* Top = "ABCDEFGH";
    cout << "  ";
    for(int i=0;i<8;i++){
        cout << i+1 << " |";
    }
    cout << endl << "  ";
    for(int i=0;i<8;i++){
        cout << "-- ";
    }
    cout << endl;
    for(int i=0;i<8;i++){
        for(int j=-1;j<8;j++){
            if(j==-1){
                cout << Top[i] << "|";
            }
            else {
                cout << ToChar(chessBoard->getPiece(i, j)) << "|";
            }
        }
        cout << endl;
    }
    cout << "  ";
    for(int i=0;i<8;i++){
        cout << "-- ";
    }
    cout << endl;
}