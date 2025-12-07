// chessboard.h
#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPixmap>
#include <QIcon>

class ChessBoard : public QDialog
{
    Q_OBJECT

public:
    ChessBoard(QWidget *parent = nullptr);
    ~ChessBoard();

private:
    void setupBoard();
    void setupPieces();
    void setPiece(int row, int col, const QString& pieceName);

    QPushButton* squares[8][8];
    QGridLayout* gridLayout;
};

#endif // CHESSBOARD_H
