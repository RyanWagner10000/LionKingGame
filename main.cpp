#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "player.h"

std::vector<std::string> characterInfo(int character_num)
{
    /*
    Sources:
    https://stackoverflow.com/questions/9206669/making-a-table-with-printf-in-c
    https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    */
    std::string line;
    std::ifstream myfile("../../characters.txt");
    char counter = 0;
    std::vector<std::string> line_split = {" ", " ", " ", " ", " ", " "};

    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (character_num == counter)
            {
                std::string token;
                for (int i = 0; i < 6; i++)
                {
                    token = line.substr(0, line.find("|"));
                    line_split[i] = token;
                    line.erase(0, line.find("|") + 1);
                }
                break;
            }
            counter++;
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";

    return line_split;
}

void printCharacters(std::vector<int> lines2print)
{
    /*
    Sources:
    https://stackoverflow.com/questions/9206669/making-a-table-with-printf-in-c
    https://stackoverflow.com/questions/14265581/parse-split-a-string-in-c-using-string-delimiter-standard-c
    */
    std::string line;
    std::ifstream myfile("../../characters.txt");
    char counter = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            if (counter == 0)
            {
                printf("%-4s%-10s%-10s%-10s%-10s%-10s%-10s\n", " ", "Name", "Age", "Strength", "Stamina", "Wisdom", "Pride Points");
            }
            else if (std::find(lines2print.begin(), lines2print.end(), counter) != lines2print.end())
            {
                std::string line_split[6];

                std::string token;
                for (int i = 0; i < 6; i++)
                {
                    token = line.substr(0, line.find("|"));
                    line_split[i] = token;
                    line.erase(0, line.find("|") + 1);
                }

                printf("%-4d%-10s%-8s%-10s%-10s%-10s%-10s\n", counter, line_split[0].c_str(), line_split[1].c_str(), line_split[2].c_str(), line_split[3].c_str(), line_split[4].c_str(), line_split[5].c_str());
            }
            counter++;
        }
        myfile.close();
    }

    else
        std::cout << "Unable to open file";

    return;
}

int introNumPlayers()
{
    std::cout << "Hello! Welcome to The Circle of Life Game!\n"
              << std::endl;

    std::cout << "How many players will be playing this game [2-5]?\nNumber of players: ";

    int num_players;
    std::cin >> num_players;

    while (true)
    {
        if (num_players >= 2 && num_players <= 5)
        {
            std::cout << "\nGreat! " << num_players << " players will be playing the game.\n"
                      << std::endl;
            break;
        }
        else
        {
            std::cout << "\nI'm sorry, you entered a number that wasn't between 2 and 5 for the number of players." << std::endl;
            std::cout << "Please retry ..." << std::endl;
            std::cout << "How many players will be playing this game [2-5]?\nNumber of players: ";
            std::cin >> num_players;
        }
    }

    return num_players;
}

int playerPickPath(int playerId)
{
    int option = 0;

    while (true)
    {
        std::cout << "Player " << playerId << ": please pick the path you want to follow for your character." << std::endl;
        printf("%-4s%-30s\n", "1", "Cub Training");
        printf("%-4s%-30s\n", "2", "Straight to the Pride Lands");
        std::cout << "Pick: ";

        std::cin >> option;

        if (option == 1 || option == 2)
        {
            return option - 1;
            break;
        }
        else
        {
            std::cout << "You entered a number that wasn't part of the list, please retry.\n";
        }
    }
}

std::vector<Player> buildPlayerVector(int num_players)
{
    std::vector<Player> players;
    std::vector<int> lines2print = {1, 2, 3, 4, 5};
    int player_num = -1;
    int i = 0;

    for (i = 0; i < num_players; i++)
    {
        while (true)
        {
            std::cout << "\nPlayer " << i + 1 << ": please pick your character from the list below." << std::endl;
            std::cout << "Enter the number you see on the left-hand side of the list." << std::endl;
            printCharacters(lines2print);
            std::cout << "\nPick: ";
            std::cin >> player_num;

            if (std::find(lines2print.begin(), lines2print.end(), player_num) != lines2print.end())
            {
                // Get the character info from the character.txt file
                std::vector<std::string> character_info = characterInfo(player_num);

                // Create a new player object, let player pick their path, add it to the players vector
                Player new_player(player_num, character_info[0], std::stoi(character_info[1]), std::stoi(character_info[2]), std::stoi(character_info[3]), std::stoi(character_info[4]), std::stoi(character_info[5]));
                new_player.setPath(playerPickPath(new_player.getPlayerID()));
                new_player.setTurnOrder(i);
                players.push_back(new_player);

                // Make the index in this vector -1 so it doesn't get printed again
                lines2print[player_num - 1] = -1;

                break;
            }
            else
            {
                if (player_num < 2 || player_num > 5)
                {
                    std::cout << "Sorry, number " << player_num << " is outside the range of players. Please try another.\n"
                              << std::endl;
                }
                else
                {
                    std::cout << "Sorry, number " << player_num << " is already taken. Please try another.\n"
                              << std::endl;
                }
            }
        }
    }

    return players;
}

std::vector<Player> setPlayerTurnOrder(std::vector<Player> playerVect)
{
    /*
    Sources:
    rand int within range: https://stackoverflow.com/questions/7560114/random-number-c-in-some-range
    */

    std::cout << "\nAssigning random turn order to all players ..." << std::endl;
    std::vector<int> vec;

    for (int i = 0; i < playerVect.size(); i++)
    {
        vec.push_back(0);
    }

    // Initialize random seed
    srand(time(0));

    // Initialize random number variable
    int randomNumber = 0;

    int counter = 0;
    bool same = false;
    while (counter != playerVect.size())
    {
        // Generate a random number within a given range [1, length of players vect]
        vec[counter] = 1 + (std::rand() % (vec.size() - 1 + 1));
        for (int i = 0; i < vec.size(); i++)
        {
            if (i == counter)
            {
                continue;
            }
            else if (vec[counter] == vec[i])
            {
                same = true;
            }
        }
        if (!same)
        {
            counter++;
        }
        same = false;
    }

    std::cout << "Turn Order for players:" << std::endl;
    for (int i = 0; i < playerVect.size(); i++)
    {
        playerVect[i].setTurnOrder(vec[i]);
        std::cout << "  Player " << playerVect[i].getPlayerID() << ": goes " << vec[i] << std::endl;
    }
    std::cout << std::endl;

    // Reorder the Player vecotr from first turn to last turn. Makes it easier for game play loop
    std::vector <Player> new_player_order;
    for (int i = 0; i < playerVect.size(); i++) {
        for (int j = 0; j < playerVect.size(); j++) {
            if (playerVect[j].getTurnOrder() == i+1) {
                new_player_order.push_back(playerVect[j]);
                break;
            }
        }
    }

    std::cout << "Turn Order for players:" << std::endl;
    for (int i = 0; i < new_player_order.size(); i++)
    {
        std::cout << "  Player " << new_player_order[i].getPlayerID() << ": goes " << new_player_order[i].getTurnOrder() << std::endl;
    }
    std::cout << std::endl;

    return new_player_order;
}

int main()
{
    std::vector<int> lines2print = {1, 2, 3, 4, 5};
    int num_players = introNumPlayers();

    // Build vector of Players for num_players of new players
    std::vector<Player> playerVect = buildPlayerVector(num_players);

    playerVect = setPlayerTurnOrder(playerVect);

    return 0;
}