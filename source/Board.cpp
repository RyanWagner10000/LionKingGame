#include <string>
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

#include "include/board.h"

void Board::initializeBoard()
{
    // Seed random number generator in your main function once
    for (int i = 0; i < 2; i++)
    {
        initializeTiles(i); // This ensures each lane has a unique tile distribution
    }
}

void Board::initializeTiles(int player_index)
{
    Tile temp;
    int green_count = 0;
    int total_tiles = _BOARD_SIZE;
    // Keep track of green tile positions to ensure we place exactly 30 greens
    for (int i = 0; i < total_tiles; i++)
    {
        if (i == total_tiles - 1)
        {
            // Set the last tile as Orange for "Pride Rock"
            temp.setColor("Orange");
        }
        else if (i == 0)
        {
            // Set the last tile as Yellow for "Beginnning"
            temp.setColor("Gray");
        }
        else if (green_count < 30 && (rand() % (total_tiles - i) < 30 - green_count))
        {
            temp.setColor("Green");
            green_count++;
        }
        else
        {
            // Randomly assign one of the other colors: Blue, Pink, Brown, Red, Purple
            int color_choice = rand() % 5;
            switch (color_choice)
            {
            case 0:
                temp.setColor("Blue"); // Blue
                break;
            case 1:
                temp.setColor("Pink"); // Pink
                break;
            case 2:
                temp.setColor("Brown"); // Brown
                break;
            case 3:
                temp.setColor("Red"); // Red
                break;
            case 4:
                temp.setColor("Purple"); // Purple
                break;
            }
        }
        // Assign the tile to the board for the specified lane
        _tiles[player_index][i] = temp;
    }
}

Board::Board()
{
    _player_count = 1;
    // Initialize player position
    _player_position[0] = 0;
    // Initialize tiles
    // initializeTiles();
}

Board::Board(int player_count)
{
    if (player_count > _MAX_PLAYERS)
    {
        _player_count = _MAX_PLAYERS;
    }
    else
    {
        _player_count = player_count;
    }
    // Initialize player position
    for (int i = 0; i < _player_count; i++)
    {
        _player_position[i] = 0;
    }
    // Initialize tiles
    initializeBoard();
}

std::string Board::isPlayerOnTile(int path_index, int pos)
{
    std::string playersOnTile = "";
    int len = sizeof(_player_position) / sizeof(_player_position[0]);

    for (int i = 0; i < len; i++)
    {
        if (_player_path[i] == path_index && _player_position[i] == pos)
        {
            playersOnTile.append(std::to_string(i + 1));
            playersOnTile.append("&");
        }
    }

    if (playersOnTile.size() > 0)
    {
        playersOnTile.pop_back();
    }

    return playersOnTile;
}

void Board::displayTile(int path_index, int pos)
{
    // string space = " ";
    std::string color = "";
    std::string playersOnTile = isPlayerOnTile(path_index, pos);
    // Template for displaying a tile: <line filler space> <color start> |<player symbol or blank space>| ...continued below
    // <reset color> <line filler space> <endl>
    // Determine color to display

    color = _tiles[path_index][pos].getColor();

    if (playersOnTile.size() > 0)
    {
        std::cout << color << "|" << playersOnTile << "|" << RESET;
    }
    else
    {
        std::cout << color << "| |" << RESET;
    }
}

void Board::displayTrack(int path_index)
{
    for (int i = 0; i < _BOARD_SIZE; i++)
    {
        displayTile(path_index, i);
    }
    std::cout << std::endl;
}

void Board::displayBoard()
{
    for (int i = 0; i < 2; i++)
    {
        displayTrack(i);
        if (i == 0)
        {
            std::cout << std::endl; // Add an extra line between the two lanes
        }
    }
}

bool Board::movePlayer(int player_index, int move_amount)
{
    // Increment player position
    _player_position[player_index] += move_amount;
    if (_player_position[player_index] >= _BOARD_SIZE - 1)
    {
        // Player reached last tile
        return true;
    }
    return false;
}

int Board::getPlayerPosition(int player_index) const
{
    if (player_index >= 0 && player_index <= _player_count)
    {
        return _player_position[player_index];
    }
    return -1;
}

void Board::setPlayerPaths(int idx, int path)
{
    _player_path[idx] = path;
}
// Working on adding positions to track each character ie.. _ _ _ _ per each tile and have tiles better sorted for functionality of the
// game

// Add functions that would control random events and the specific catches of the game as well as the fufilling the outlined requirements