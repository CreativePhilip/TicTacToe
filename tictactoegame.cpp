#include "tictactoegame.h"


TicTacToeGame::TicTacToeGame()
{
    resetGameState();
}


void TicTacToeGame::resetGameState() {
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            gameFields[i][j] = CellType::Empty;
        }
    }

    currentPlayer = Player::X;
}

void TicTacToeGame::printGameState() {
    for (int i=0; i<3; i++) {
        qDebug() << gameFields[i][0] << gameFields[i][1] << gameFields[i][2];
    }
}

void TicTacToeGame::move(int cellNumber)
{
    if (isMoveValid(cellNumber)) {
        CellCoordinate c = convertTo2dCoordinates(cellNumber);
        gameFields[c.i][c.j] = currentPlayer == Player::X ? CellType::Xs : CellType::Os;

        changePlayer();

        if (checkIfGameHasEnded()) gameState = GameState::Finished;

    }
}

CellType TicTacToeGame::getCellValue(int index)
{
    CellCoordinate c = convertTo2dCoordinates(index);
    return gameFields[c.i][c.j];
}

Player TicTacToeGame::getCurrentPlayer()
{
    return currentPlayer;
}

GameState TicTacToeGame::getGameState()
{
    return gameState;
}

bool TicTacToeGame::checkIfGameHasEnded()
{
    for (int i=0; i<3; i++) {
        if(gameFields[i][0] == gameFields[i][1] && gameFields[i][0] == gameFields[i][2] && gameFields[i][0] != CellType::Empty) return true;
        if(gameFields[0][i] == gameFields[1][i] && gameFields[0][i] == gameFields[2][i] && gameFields[0][i] != CellType::Empty) return true;
    }
    if(gameFields[0][0] == gameFields[1][1] && gameFields[0][0] == gameFields[2][2] && gameFields[0][0] != CellType::Empty) return true;
    if(gameFields[0][2] == gameFields[1][1] && gameFields[0][2] == gameFields[2][0] && gameFields[2][0] != CellType::Empty) return true;
    return false;
}

void TicTacToeGame::changePlayer()
{
    currentPlayer = currentPlayer == Player::X ? Player::O : Player::X;
}

bool TicTacToeGame::isMoveValid(int cellNumber)
{
    CellCoordinate c = convertTo2dCoordinates(cellNumber);
    return gameFields[c.i][c.j] == CellType::Empty ? true : false;
}

CellCoordinate TicTacToeGame::convertTo2dCoordinates(int cellNumber){
    return CellCoordinate{
        .i = cellNumber / 3,
        .j = cellNumber % 3,
    };
}
