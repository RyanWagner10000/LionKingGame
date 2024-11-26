#ifndef PLAYER_H
#define PLAYER_H

#include <string>

// CUB_TRAINING = 0
// STRIGHT_TO_PRIDE_LANDS = 1

class Player
{
public:
    Player(int id, std::string name, int age, int strength, int stamina, int wisdom, int pride);
    Player();

    int getPlayerID();
    void setPlayerID(int new_id);

    std::string getName();
    void setName(std::string new_name);

    int getAge();
    void setAge(int age);

    int getStrength();
    void setStrength(int new_strength);
    void addStrength(int value);
    void subStrength(int value);

    int getStamina();
    void setStamina(int new_stamina);
    void addStamina(int value);
    void subStamina(int value);

    int getWisdom();
    void setWisdom(int new_wisdom);
    void addWisdom(int value);
    void subWisdom(int value);

    int getPridePoints();
    void setPridePoints(int new_pride);
    void addPridePoints(int value);
    void subPridePoints(int value);

    int getPath();
    void setPath(int new_path);

    int getTurnOrder();
    void setTurnOrder(int new_order);

private:
    int id = -1;
    std::string name = "";
    int age = 0;
    int strength = 0;
    int stamina = 0;
    int wisdom = 0;
    int pride_points = 0;
    int path = -1;
    int turn_order = -1;
};

#endif // PLAYER_H