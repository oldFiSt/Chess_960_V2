#include "chess960_logic.h"
#include <algorithm>
#include <random>
#include <ctime>

Chess960Logic::Chess960Logic()
{
    std::srand(static_cast<unsigned int>(std::time(nullptr)));
}

void Chess960Logic::generatePosition()
{
    // Массив для отслеживания количества фигур
    std::vector<std::pair<std::string, int>> cnt_array = {
        {"King", 1}, {"Queen", 1}, {"Rook", 2}, {"Bishop", 2}, {"Knight", 2}
    };

    // Массив для расстановки
    std::string positions[8] = {"", "", "", "", "", "", "", ""};

    // Расставляем слоны на разных цветах клеток
    int bishop1_pos, bishop2_pos;
    do {
        bishop1_pos = std::rand() % 4 * 2; // четные позиции (0, 2, 4, 6)
        bishop2_pos = std::rand() % 4 * 2 + 1; // нечетные позиции (1, 3, 5, 7)
    } while (bishop1_pos == bishop2_pos);

    positions[bishop1_pos] = "Bishop";
    positions[bishop2_pos] = "Bishop";
    change_value(cnt_array, "Bishop");
    change_value(cnt_array, "Bishop");

    // Расставляем ферзя
    int queen_pos;
    do {
        queen_pos = std::rand() % 8;
    } while (!positions[queen_pos].empty());

    positions[queen_pos] = "Queen";
    change_value(cnt_array, "Queen");

    // Расставляем двух коней
    for (int i = 0; i < 2; ++i) {
        int knight_pos;
        do {
            knight_pos = std::rand() % 8;
        } while (!positions[knight_pos].empty());

        positions[knight_pos] = "Knight";
        change_value(cnt_array, "Knight");
    }

    // Оставшиеся 3 позиции - это ладьи и король между ними
    int empty_positions[3];
    int index = 0;
    for (int i = 0; i < 8; ++i) {
        if (positions[i].empty()) {
            empty_positions[index++] = i;
        }
    }

    // Упорядочиваем позиции
    std::sort(empty_positions, empty_positions + 3);

    // Расставляем ладьи и короля
    positions[empty_positions[0]] = "Rook";
    positions[empty_positions[1]] = "King";
    positions[empty_positions[2]] = "Rook";

    // Сохраняем результат
    for (int i = 0; i < 8; ++i) {
        if (positions[i] == "King") backRank[i] = "K";
        else if (positions[i] == "Queen") backRank[i] = "Q";
        else if (positions[i] == "Rook") backRank[i] = "R";
        else if (positions[i] == "Bishop") backRank[i] = "B";
        else if (positions[i] == "Knight") backRank[i] = "N";
    }
}

std::string Chess960Logic::getPieceCode(int position) const
{
    if (position >= 0 && position < 8) {
        return backRank[position];
    }
    return "";
}

int Chess960Logic::take_value(std::vector<std::pair<std::string, int>> &array, std::string str)
{
    for (auto &pair : array) {
        if (pair.first == str) {
            return pair.second;
        }
    }
    return 0;
}

void Chess960Logic::change_value(std::vector<std::pair<std::string, int>> &array, std::string str)
{
    for (auto &pair : array) {
        if (pair.first == str && pair.second > 0) {
            pair.second--;
            break;
        }
    }
}
