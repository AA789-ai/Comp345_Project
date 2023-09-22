#include "Orders.h"
#include <iostream>
using namespace std;

// Base Order Class constructor
Order::Order()
{

	std::cout << "Created Order base" << std::endl;

}

// Base Order Class deconstructor
Order::~Order()
{
	std::cout << "Deconstructor Order base" << std::endl;
}

// OrdersList class 

void OrdersList::remove()
{
	
}

void OrdersList::move()
{

}

/*
	Override stream insertion operator
*/
ostream& operator<<(ostream& os, const Order& order)
{

	if (order.type == "Deploy")
	{
		os << order.type << " - Deploys armies to the terrorities\n";
	}
	else if (order.type == "Advance")
	{
		os << order.type << " - Advance armies to the terrorities\n";
	}
	else
	{
		os << "Invalid order!";
	}
	
	return os;
}

// Deploy class constructor

Deploy::Deploy(int numOfArmyUnits)
{
	std::cout << "Created Deploy order" << std::endl;
	this->type = "Deploy";
}

bool Deploy::validate()
{
	std::cout << "validate Deploy order\n";
	return true;
}

void Deploy::execute()
{
	if (this->validate())
	{
		std::cout << "execute Deploy order\n";
	}	
}

//  Advance class
/*
	Advance class constructor. Parameters include number of armies to move, source territory, and target terroritory
*/
Advance::Advance()
{
	std::cout << "Created Advance order" << std::endl;
	this->type = "Advance";
}

/*
	Advance validate checks if source territory and target territory. 
*/ 
bool Advance::validate()
{
	std::cout << "validate Advance order\n";
	return true;
}

/*
	Executes Advance order and begins attack from source territory to target territory
*/
void Advance::execute()
{
	if (this->validate())
	{
		std::cout << "execute Advance order\n";
	}
	
}

// Bomb class
/*
	Bomb class constructor. Parameters include target territory to bomb
*/
Bomb::Bomb()
{
	std::cout << "Created Bomb order" << std::endl;
	this->type = "Bomb";
}

/*
	Bomb validate checks if the target territory is validate
*/
bool Bomb::validate()
{
	std::cout << "validate Bomb order\n";
	return true;
}

/*
	Executes Bomb order reducing territory army value by half
*/
void Bomb::execute()
{
	if (this->validate())
	{
		std::cout << "execute Bomb order\n";
	}
}

// Blockade class
/*
	Blockade class constructor. Parameters include target territory
*/
Blockade::Blockade()
{
	std::cout << "Created Blockade order" << std::endl;
	this->type = "Blockade";
}

/*
	Blockade validate checks if the target territory is validate
*/
bool Blockade::validate()
{
	std::cout << "validate Blockade order\n";
	return true;
}

/*
	Executes Blockade which turns target territory into a neutral territory and triple the army value
*/
void Blockade::execute()
{
	if (this->validate())
	{
		std::cout << "execute Blockade order\n";
	}
}

// Airlift class
/*
	Airlift class constructor. Parameters include the number of armies, source territory and target territory
*/
Airlift::Airlift()
{
	std::cout << "Created Airlift order" << std::endl;
	this->type = "Airlift";
}

/*

*/
bool Airlift::validate()
{
	std::cout << "validate Airlift order\n";
	return true;
}

/*

*/
void Airlift::execute()
{
}

// Negotiate class
/*
	Negotiate class constructor. Parameters include target player 
*/
Negotiate::Negotiate()
{
	std::cout << "Created Negotiate order" << std::endl;
	this->type = "Negotiate";
}

/*

*/
bool Negotiate::validate()
{
	std::cout << "validate Negotiate order\n";
	return true;
}

/*

*/
void Negotiate::execute()
{
	if (this->validate())
	{
		std::cout << "execute Negotiate order\n";
	}
}

