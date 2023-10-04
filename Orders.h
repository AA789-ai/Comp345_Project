#pragma once
#include <iostream>
#include <vector>
#include "map.h"

// Order base class 
class Order
{
public:
	// Constructor
	Order();
	
	// Override ostream operator
	friend std::ostream& operator<< (std::ostream& os, Order& order);

	// Class member attributes
	std::string type = "Invalid";

	// Destructor
	~Order();

protected:

	// Derive class methods
	virtual bool validate();
	virtual void execute();

};

// OrdersList class 
class OrdersList
{
public:
	// Constructor
	OrdersList();

	void remove(Order& order);
	void move(Order& order, const int target_index);

	// Debug methods
	void print();

	// Class attributes
	std::vector<Order*> orders;

	// Destructor
	~OrdersList();
};

// Deploy Order class 
class Deploy : public Order
{
public:
	// Constructor
	Deploy(int numOfArmyUnits);

	//Copy Constructor
	Deploy(Deploy& other);
	
	// Class methods
	bool validate();
	void execute();


};

// Advance Order class 
class Advance : public Order
{
public:
	// Constructor
	Advance();

	//Copy Constructor
	Advance(Advance& other);

	// Class methods
	bool validate();
	void execute();

};

// Bomb Order class 
class Bomb : public Order
{
public:
	// Constructor 
	Bomb();

	//Copy Constructor
	Bomb(Bomb& other);

	// Class methods
	bool validate();
	void execute();

};

// Blockade Order class
class Blockade : public Order
{
public:
	// Constructor
	Blockade();

	//Copy Constructor
	Blockade(Blockade& other);

	// Class methods
	bool validate();
	void execute();

};

// Airlift Order class
class Airlift : public Order
{
public:
	// Constructor
	Airlift();

	//Copy Constructor
	Airlift(Airlift& other);

	// Class methods
	bool validate();
	void execute();

};

// Negotiate order class
class Negotiate : public Order
{
public:
	// Constructor 
	Negotiate();

	//Copy Constructor
	Negotiate(Negotiate& other);

	// Class methods
	bool validate();
	void execute();

};






