#include "Player.h"

// Define the testPlayers function to demonstrate player object features
void testPlayers() {
    // Create a player with the name "John"
    std::cout << "<----------Creating Player---------->" << std::endl;
    Player* player = new Player("John");

    // Add territories to the player's owned territories
    std::cout << "<----------Adding Territories---------->" << std::endl;
    Territory* territory1 = new Territory("New York", 1, 2);
    Territory* territory2 = new Territory("London", 3, 4);
    player->addTerritory(territory1);

    // Get the territories to defend (initially, it returns all owned territories)
    std::vector<Territory*> territoriesToDefend = player->toDefend();

    // Display the territories to defend
    std::cout << "<----------Displaying Territories To Defend---------->" << std::endl;
    std::cout << "Territories to Defend: ";
    for (const Territory* territory : territoriesToDefend) {
        std::cout << territory->getName() << " - ";
    }
    std::cout << std::endl;

    // Get the territories to attack (initially, it returns an empty list)
    std::vector<Territory*> territoriesToAttack = player->toAttack();

    // Display the territories to attack
    std::cout << "<----------Displaying Territories To Attack---------->" << std::endl;
    std::cout << "Territories to Attack: ";
    for (const Territory* territory : territoriesToAttack) {
        std::cout << territory->getName() << ", ";
    }
    std::cout << std::endl;

    // Get the player's orders list
    OrdersList& playerOrders = player->getOrdersList();

    // Issue some orders
    std::cout << "<----------Issuing Orders---------->" << std::endl;
//    player->issueOrder("Airlift", territory1, territory2, new int(50), nullptr, nullptr, nullptr);
//    player->issueOrder("Bomb", nullptr, territory2, nullptr, nullptr, nullptr, nullptr);


    // Display the player's orders list
    std::cout << "<----------Displaying Orders List---------->" << std::endl;
    playerOrders.print();

    // Testing reinforcementPool
    std::cout << "<----------Number of reinforcement pool---------->" << std::endl;
    player->setReinforcementPool(50);
    player->addReinforcementPool(100);
    player->removeReinforcementPool(40);
    std::cout << player->getReinforcementPool() << std::endl;

    Deck* deck = new Deck();
    std::cout << *deck << std::endl;

    deck->draw(player->getHand());
    deck->draw(player->getHand());

    std::cout << player->getHand() << std::endl;
    player->getHand().cards[0]->play(player->getHand(), 0, player->getOrdersList());


    // Use the custom operator<< to print player details
    std::cout << "<----------Player's Stats---------->" << std::endl;
    std::cout << *player << std::endl;


    // Clean up the player to prevent memory leaks
    std::cout << "<----------Deleting Player---------->" << std::endl;
    delete player;
}

//int main() {
//    // Call the testPlayers function to demonstrate player object features
//    testPlayers();
//    return 0;
//}