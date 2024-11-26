#ifndef BOARD_H
#define BOARD_H

#include <vector>

#include "include/tile.h"

class Board
{
public:
    Board();
    Board(int player_count);
    void displayTrack(int player_index);
    void initializeBoard();
    void displayBoard();
    void setPlayerPaths(int idx, int path);
    bool movePlayer(int player_index, int move_amount);
    int getPlayerPosition(int player_index) const;

private:
    static const int _BOARD_SIZE = 52;
    Tile _tiles[2][_BOARD_SIZE];
    static const int _MAX_PLAYERS = 5;
    int _player_count;
    int _player_position[_MAX_PLAYERS];
    int _player_path[_MAX_PLAYERS];
    void displayTile(int player_index, int pos);
    void initializeTiles(int player_index);
    std::string isPlayerOnTile(int player_index, int pos);
};

#endif
