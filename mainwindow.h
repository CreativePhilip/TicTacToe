#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tictactoegame.h"

#include <QMainWindow>
#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    TicTacToeGame game;

    void updateUiGameState();
    QString textFromCellState(CellType cell);

private slots:
    void gameButtonPressedHandler();
    void startGameButtonPressHandler();

};
#endif // MAINWINDOW_H
