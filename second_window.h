#ifndef SECOND_WINDOW_H
#define SECOND_WINDOW_H

#include <QDialog>
#include <QPushButton>
#include <vector>
#include <string>
#include <utility>
#include "chess960_logic.h"

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
    void setPiece(int row, int col, const std::string& pieceCode);
    std::string getPieceSymbol(const std::string& pieceCode);

    Ui::Second_window *ui;
    QPushButton* squares[8][8];
    std::string chessBoardState[8][8];
    QPushButton* selectedCell;
    int selectedRow, selectedCol;
    Chess960Logic chess960;
};

#endif // SECOND_WINDOW_H
