// chessboard.cpp
#include "chessboard.h"

ChessBoard::ChessBoard(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Шахматная доска");
    setGeometry(0, 0, 800, 800);

    // Создаем центральный виджет
    QWidget *centralWidget = new QWidget(this);
    centralWidget->setGeometry(80, 90, 640, 640);

    // Создаем grid layout
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(0);
    gridLayout->setContentsMargins(0, 0, 0, 0);

    setupBoard();
    setupPieces();
}

ChessBoard::~ChessBoard()
{
}

void ChessBoard::setupBoard()
{
    // Создаем шахматные клетки
    for (int row = 0; row < 8; ++row) {
        QHBoxLayout *hLayout = new QHBoxLayout();
        hLayout->setSpacing(0);

        for (int col = 0; col < 8; ++col) {
            QPushButton *square = new QPushButton();
            square->setFixedSize(80, 80);
            square->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);

            // Устанавливаем цвет клетки
            if ((row + col) % 2 == 0) {
                square->setStyleSheet("background-color: rgb(200, 143, 104);");
            } else {
                square->setStyleSheet("background-color: rgb(135, 68, 0);");
            }

            squares[row][col] = square;
            hLayout->addWidget(square);
        }

        gridLayout->addLayout(hLayout, row, 0);
    }
}

void ChessBoard::setupPieces()
{
    // Расставляем черные фигуры
    setPiece(0, 0, "black_rook");
    setPiece(0, 1, "black_knight");
    setPiece(0, 2, "black_bishop");
    setPiece(0, 3, "black_queen");
    setPiece(0, 4, "black_king");
    setPiece(0, 5, "black_bishop");
    setPiece(0, 6, "black_knight");
    setPiece(0, 7, "black_rook");

    // Черные пешки
    for (int col = 0; col < 8; ++col) {
        setPiece(1, col, "black_pawn");
    }

    // Белые фигуры
    setPiece(7, 0, "white_rook");
    setPiece(7, 1, "");
    setPiece(7, 2, "white_bishop");
    setPiece(7, 3, "white_queen");
    setPiece(7, 4, "white_king");
    setPiece(7, 5, "white_bishop");
    setPiece(7, 6, "white_knight");
    setPiece(7, 7, "white_rook");

    // Белые пешки
    for (int col = 0; col < 8; ++col) {
        setPiece(6, col, "white_pawn");
    }
}

void ChessBoard::setPiece(int row, int col, const QString& pieceName)
{
    // Формируем путь к изображению
    QString imagePath = QString(":/pieces/%1.png").arg(pieceName);

    // Создаем QPixmap и устанавливаем как иконку
    QPixmap pixmap(imagePath);
    if (!pixmap.isNull()) {
        QIcon icon(pixmap);
        squares[row][col]->setIcon(icon);
        squares[row][col]->setIconSize(QSize(60, 60));
    }
}
