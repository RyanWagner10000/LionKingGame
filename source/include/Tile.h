#ifndef TILE_H
#define TILE_H

#include <string>

#define RED "\033[;41m"
#define GREEN "\033[;42m"
#define YELLOW "\033[;43m"
#define BLUE "\033[;44m"
#define MAGENTA "\033[;45m"
#define CYAN "\033[;46m"
#define WHITE "\033[;47m"
#define RESET "\033[;0m"

#define PURPLE "\033[48;5;129m"
#define BROWN "\033[48;5;94m"
#define PINK "\033[48;5;218m"
#define ORANGE "\033[48;5;208m"
#define GRAY "\033[48;5;8m"

class Tile
{
public:
    Tile();
    std::string getColor();
    void setColor(std::string new_color);

private:
    std::string color;
};

#endif // TILE_H