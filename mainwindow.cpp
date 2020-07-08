#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    for (int i=0; i<9; i++) {
        QString buttonName = "button" +  QString::number(i);
        QPushButton *button = MainWindow::findChild<QPushButton *>(buttonName);
        connect(button, SIGNAL(released()), this, SLOT(gameButtonPressedHandler()));
    }
    connect(ui->startGameButton, SIGNAL(released()), this, SLOT(startGameButtonPressHandler()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateUiGameState()
{
    ui->button0->setText(textFromCellState(game.getCellValue(0)));
    ui->button1->setText(textFromCellState(game.getCellValue(1)));
    ui->button2->setText(textFromCellState(game.getCellValue(2)));
    ui->button3->setText(textFromCellState(game.getCellValue(3)));
    ui->button4->setText(textFromCellState(game.getCellValue(4)));
    ui->button5->setText(textFromCellState(game.getCellValue(5)));
    ui->button6->setText(textFromCellState(game.getCellValue(6)));
    ui->button7->setText(textFromCellState(game.getCellValue(7)));
    ui->button8->setText(textFromCellState(game.getCellValue(8)));

    if(game.getCurrentPlayer() == Player::X) ui->playerLabel->setText("Current player: X");
    else ui->playerLabel->setText("Current player: O");
}

QString MainWindow::textFromCellState(CellType cell)
{
    switch (cell) {
        case CellType::Xs:
        return QString("X");
        break;

        case CellType::Os:
        return QString("O");
        break;

        default:
        return QString("");
        break;
    }
}

void MainWindow::gameButtonPressedHandler()
{
    QPushButton *button = (QPushButton *)sender();
    int cellNumber = button->objectName().right(1).toInt();

    game.move(cellNumber);
    updateUiGameState();

    game.printGameState();
    qDebug() << "";

    if (game.getGameState() == GameState::Finished) {
        QMessageBox msg;
        msg.setText("Game over");
        msg.exec();
        game.resetGameState();
        updateUiGameState();
        ui->stackedWidget->setCurrentIndex(Page::Starting);
    }
}

void MainWindow::startGameButtonPressHandler()
{
    ui->stackedWidget->setCurrentIndex(Page::Game);
}

