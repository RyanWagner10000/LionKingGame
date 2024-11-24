#ifndef TILE_H
#define TILE_H

#define RED "\033[48;2;230;10;10m"
#define GREEN "\033[48;2;34;139;34m" /* Grassy Green (34,139,34) */
#define BLUE "\033[48;2;10;10;230m"
#define PINK "\033[48;2;255;105;180m"
#define BROWN "\033[48;2;139;69;19m"
#define PURPLE "\033[48;2;128;0;128m"
#define ORANGE "\033[48;2;230;115;0m" /* Orange (230,115,0) */
#define GREY "\033[48;2;128;128;128m" /* Grey (128,128,128) */
#define RESET "\033[0m"


// I am not sure if I need something else outside of this for this file

// Add function to account for the chances of survival tiles 

// Possibly add the actual tile set up so that game is played in format of _ _ _ _ per tile to help with readability and functionality

#ifndef TILE_H
#define TILE_H

#include <string>

using namespace std;

class Tile 
{
private:
    string type;  // Type of the tile (ie.. regular, special, etc.)
    string eventDescription;  // Description of the event for this tile
    int effectValue;   // Effect on the player's stats (Pride Points, Stamina, etc.)

public:
    // Constructor to initialize the tile
    Tile(string type = "regular", string eventDescription = "", int effectValue = 0);

    // Getter and setter for type
    string getType() const;
    void setType(string type);

    // Getter and setter for eventDescription
    string getEventDescription() const;
    void setEventDescription(string eventDescription);

    // Getter and setter for effectValue
    int getEffectValue() const;
    void setEffectValue(int effectValue);
};

#endif
