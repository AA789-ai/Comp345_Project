#include "Player.h" // Include the header file for the Player class

// Constructor for the Player class
Player::Player(const std::string& playerName) : playerName(playerName) {}

// Destructor for the Player class
Player::~Player() {
    // Delete owned territories to prevent memory leaks
    for (Territory* territory : ownedTerritories) {
        delete territory;
    }
}

// Add a territory to the player's ownedTerritories or territories to be defended
void Player::addTerritory(Territory* territory) {
    ownedTerritories.push_back(territory);
}

// Remove a territory from ownedTerritories or territories to be defended
bool Player::removeTerritory(Territory* territory) {
    // Find the territory in the list of owned territories
    auto it = std::find(ownedTerritories.begin(), ownedTerritories.end(), territory);

    if (it != ownedTerritories.end()) {
        // Territory found, erase it from the list
        ownedTerritories.erase(it);
        delete territory; // Delete the removed territory to prevent memory leaks
        return true; // Territory successfully removed
    }

    return false; // Territory not found
}


// Get a list of territories to be defended (currently returns all owned territories)
std::vector<Territory*> Player::toDefend() {
    // For now, return all owned territories as an arbitrary choice.
    return ownedTerritories;
}

// Get a list of territories to be attacked (currently returns an empty list)
std::vector<Territory*> Player::toAttack() {
    // For now, return an empty list as an arbitrary choice.
    return std::vector<Territory*>();
}

// Get the player's hand of cards
const Hand& Player::getHand() const {
    return hand;
}

// Get the player's list of orders
const OrdersList& Player::getOrdersList() const {
    return ordersList;
}

// Create an Order object and add it to the player's list of orders
void Player::issueOrder(const std::string& orderType) {
    Order* newOrder = nullptr;

    // Create an Order object based on the orderType
    if (orderType == "Deploy") {
        newOrder = new Deploy(new int(5)); // Example with parameters
    }
    else if (orderType == "Advance") {
        newOrder = new Advance();
    }
    else if (orderType == "Bomb") {
        newOrder = new Bomb();
    }
    else if (orderType == "Blockade") {
        newOrder = new Blockade();
    }
    else if (orderType == "Airlift") {
        newOrder = new Airlift();
    }
    else if (orderType == "Negotiate") {
        newOrder = new Negotiate();
    }

    if (newOrder) {
        // Add the created order to the player's list of orders
        ordersList.add(newOrder);
    }
    else {
        // Handle unsupported order type or invalid parameters
        std::cout << "Invalid order type or parameters." << std::endl;
    }
}


