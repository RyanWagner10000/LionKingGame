#include "include/player.h"
#include <string>

// Constructor
Player::Player(int id, std::string name, int age, int strength, int stamina, int wisdom, int pride)
{
    setPlayerID(id);
    setName(name);
    setAge(age);
    setStrength(strength);
    setStamina(stamina);
    setWisdom(wisdom);
    setPridePoints(pride);
}

int Player::getPlayerID()
{
    return id;
}
void Player::setPlayerID(int new_id)
{
    id = new_id;
    return;
}

std::string Player::getName()
{
    return name;
}
void Player::setName(std::string new_name)
{
    name = new_name;
    return;
}

int Player::getAge()
{
    return age;
}
void Player::setAge(int new_age)
{
    age = new_age;
    return;
}

int Player::getStrength()
{
    return strength;
}
void Player::setStrength(int new_strength)
{
    strength = new_strength;
    return;
}
void Player::addStrength(int value)
{
    strength += value;
    return;
}
void Player::subStrength(int value)
{
    strength -= value;
    return;
}

int Player::getStamina()
{
    return stamina;
}
void Player::setStamina(int new_stamina)
{
    stamina = new_stamina;
    return;
}
void Player::addStamina(int value)
{
    stamina += value;
    return;
}
void Player::subStamina(int value)
{
    stamina -= value;
    return;
}

int Player::getWisdom()
{
    return wisdom;
}
void Player::setWisdom(int new_wisdom)
{
    wisdom = new_wisdom;
    return;
}
void Player::addWisdom(int value)
{
    wisdom += value;
    return;
}
void Player::subWisdom(int value)
{
    wisdom -= value;
    return;
}

int Player::getPridePoints()
{
    return pride_points;
}
void Player::setPridePoints(int new_pride)
{
    pride_points = new_pride;
    return;
}
void Player::addPridePoints(int value)
{
    pride_points += value;
    return;
}
void Player::subPridePoints(int value)
{
    pride_points -= value;
    return;
}

int Player::getPath()
{
    // 0 = Cub Training
    // 1 = Straight to the Pride Lands
    return path;
}
void Player::setPath(int new_path)
{
    path = new_path;
    return;
}

int Player::getTurnOrder()
{
    return turn_order;
}
void Player::setTurnOrder(int new_order)
{
    turn_order = new_order;
    return;
}