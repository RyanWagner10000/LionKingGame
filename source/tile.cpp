// #include <string>

#include "include/tile.h"

Tile::Tile()
{
    setColor("White");
}

std::string Tile::getColor()
{
    return color;
}

void Tile::setColor(std::string new_color)
{
    if (new_color == "Orange") {
        color = ORANGE;
    } else if (new_color == "Gray") {
        color = GRAY;
    } else if (new_color == "Green") {
        color = GREEN;
    } else if (new_color == "Blue") {
        color = BLUE;
    } else if (new_color == "Pink") {
        color = PINK;
    } else if (new_color == "Brown") {
        color = BROWN;
    } else if (new_color == "Red") {
        color = RED;
    } else if (new_color == "Purple") {
        color = PURPLE;
    } else {
        color = WHITE;
    }

    return;
}