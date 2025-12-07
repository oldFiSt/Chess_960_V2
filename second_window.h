#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>
#include <QPushButton>
#include <memory>
#include <vector>
#include "chess960_logic.h"
#include "piecefactory.h"

namespace Ui {
class Second_window;
}

class Second_window : public QDialog
{
    Q_OBJECT

public:
    explicit Second_window(QWidget *parent = nullptr);
    ~Second_window();

private slots:
    void onCellClicked();

private:
    void setupBoard();
    void setupPieces();
    void setPiece(int row, int col, std::unique_ptr<ChessPiece> piece);
    void movePiece(int fromRow, int fromCol, int toRow, int toCol);
    void clearSelection();

    Ui::Second_window *ui;
    QPushButton* squares[8][8];
    ChessPiece* board[8][8];  // Используем простой массив указателей

    // Для выбора фигуры
    int selectedRow = -1;
    int selectedCol = -1;

    Chess960Logic chess960;
};

#endif // SECOND_WINDOW_H
