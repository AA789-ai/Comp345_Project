#include "CardsDriver.h"
#include "GameEngineDriver.h"
#include "MapDriver.h"
#include "OrdersDriver.h"
#include "PlayerDriver.h"

int main(){

    testCards();
    std::cout << "MAP TESTS:" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    testLoadMaps();
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "PLAYER TESTS:" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    //TODO
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "ORDER TESTS:" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    testOrdersLists();
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "CARDS TESTS:" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    testCards();
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "GAME ENGINE TESTS:" << std::flush << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
    std::cout << "==================================================================================================================================================================================================================================" << std::endl;
   testGameStates();

    return 0;
}