#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "map.h"    // Header for the Territory class
#include "Cards.h"  // Header for the Cards class
#include "Orders.h" // Header for the Orders class

class Player {
public:
    // Constructor
    explicit Player(const std::string& playerID);

    // Copy constructor
    Player(const Player& other);

    // Assignment operator
    Player& operator=(const Player& other);

    // Destructor
    ~Player();

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Player& player);

    // Methods related to managing territories
    void removeTerritory(Territory* territory); // Remove a territory from the player's owned territories
    void addTerritory(Territory* territory); // Add a territory to the player's owned territories
    bool isTerritoryOwned(Territory* territory); // Checks if the player owns a specific territory
    std::vector<Territory*> getOwnedTerritories(); // Get a list of the territories the player owns
    std::vector<Territory*> toDefend();       // Get a list of territories to defend
    std::vector<Territory*> toAttack();       // Get a list of territories to attack

    // Methods related to managing cards
    Hand& getHand(); // Get the player's hand of cards

    // Method related to managing the player id
    std::string getPlayerID() const; // Get the player id

    // Methods related to managing orders
    OrdersList& getOrdersList();                    // Get the player's list of orders
    void issueOrder(const std::string& orderType);  // Issue a new order of a specified type

    // Methods related to managing negotiated players
    const std::vector<Player*>& getNegotiatedPlayers();
    void addToNegotiatedPlayers(Player* player);

    // Methods related to managing reinforcementPool
    int getReinforcementPool() const;
    void setReinforcementPool(const int& amount);
    void addReinforcementPool(const int& amount);
    void removeReinforcementPool(const int& amount);

private:
    // Attributes related to a Player's instance
    std::string* playerID;          // The name of the player
    std::vector<Territory*> ownedTerritories; // List of territories owned by the player
    Hand* hand;                      // The player's hand of cards
    OrdersList* ordersList;          // The list of orders issued by the player
    std::vector<Player*>* negotiatedPlayers; // The list of negotiated players that the player cannot attack
    int* reinforcementPool;
};

