#ifndef CHESS960_LOGIC_H
#define CHESS960_LOGIC_H

#include <vector>
#include <string>
#include <utility>

class Chess960Logic
{
public:
    Chess960Logic();
    void generatePosition();
    std::string getPieceCode(int position) const;

private:
    int take_value(std::vector<std::pair<std::string, int>> &array, std::string str); // Изменено с void на int
    void change_value(std::vector<std::pair<std::string, int>> &array, std::string str);

    std::string backRank[8];
};

#endif // CHESS960_LOGIC_H
