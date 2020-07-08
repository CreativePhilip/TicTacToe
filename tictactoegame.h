#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "utils.h"
#include <QDebug>

class TicTacToeGame
{
public:
    TicTacToeGame();
    void resetGameState();
    void printGameState();
    void move(int cellNumber);
    CellType getCellValue(int index);
    Player getCurrentPlayer();
    GameState getGameState();

private:
    CellType gameFields[3][3];
    Player currentPlayer = Player::X;
    GameState gameState = GameState::Started;
    bool checkIfGameHasEnded();

    void changePlayer();
    bool isMoveValid(int cellNumber);
    CellCoordinate convertTo2dCoordinates(int cellNumber);

};

#endif // TICTACTOEGAME_H
