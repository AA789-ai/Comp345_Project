#include <iostream>
#include <string>
#include <vector>
#include "map.h"
#include <unordered_map>

//---------------------------Territory-------------------------------

// Constructor for Territory: Initializes the name, x-coordinate, and y-coordinate.
Territory::Territory(const std::string& n, int xCord, int yCord){
    name = new std::string(n);
    x = new int(xCord);
    y = new int(yCord);
    numberOfArmies = new int (0);
}

// Destructor for Territory: Deletes the dynamically allocated members. We should not delete adjacent territories.
Territory::~Territory(){
    delete name;
    delete x;
    delete y;
    delete numberOfArmies;
    name = nullptr;
    x = nullptr;
    y = nullptr;
    numberOfArmies = nullptr;
    /*for(Territory* adjacentTerritory : adjacentTerritories){
        delete adjacentTerritory;
    }*/
}

//Copy constuctor. Just copying the pointers to adjacent territories, not the territories themselves as it won't make any sense.
Territory::Territory(const Territory& other) {
    name = new std::string(*(other.name));
    x = new int(*(other.x));
    y = new int(*(other.y));
    adjacentTerritories = other.adjacentTerritories; 
}


// Adds an adjacent territory to the current territory's adjacentTerritories vector.
void Territory::addAdjacentTerritory(Territory* territory){
    adjacentTerritories.push_back(territory);
}

//Basic getters
std::string Territory::getName() const{
    return *name;
}
int Territory::getX() const{
    return *x;
}
int Territory::getY() const{
    return *y;
}

int Territory::getNumberOfArmies() const {
    return *numberOfArmies;
}

// Getter for the adjacent territories.
const std::vector<Territory*>& Territory::getAdjacentTerritories() const {
    return adjacentTerritories;
}

//Basic setters
void Territory::setName(const std::string& n){
    delete name;
    name = new std::string(n);
}
void Territory::setX (int xCord){
    delete x;
    x = new int(xCord);
}
void Territory::setY (int yCord){
    delete y;
    y = new int(yCord);
}

void Territory::setNumberOfArmies(int numOfArmies) {
    delete numberOfArmies;
    numberOfArmies = new int(numOfArmies);
}

//Assignment Operator
Territory& Territory::operator=(const Territory& other) {
    if (this == &other) return *this; 
    delete name;
    delete x;
    delete y;
    name = new std::string(*(other.name));
    x = new int(*(other.x));
    y = new int(*(other.y));
    adjacentTerritories = other.adjacentTerritories;
    return *this;
}

//Stream insertion Operator
std::ostream& operator<<(std::ostream& out, const Territory& territory) {
    out << "Territory Name: " << territory.getName() << ", X: " << territory.getX() << ", Y: " << territory.getY() << ", Number of armies: " << territory.getNumberOfArmies();
    return out;
}





//-------------------------------Continent-----------------------------
// Constructor for Continent: Initializes the name and the number of armies.
Continent::Continent(const std::string& n, int bonus) {
    name = new std::string(n);
    this->bonus = new int(bonus);
}

// Destructor for Continent: Deletes the dynamically allocated members. We should not delete territories of a continent when deleting it.
Continent::~Continent(){
    delete name;
    delete bonus;
    name = nullptr;
    bonus = nullptr;
    /*for (Territory* territory : territories){
        delete territory;
    }*/
}

//Copy constructor. Just copying the pointers of territorries. Not the territories themselves as it doesn't make sense.
Continent::Continent(const Continent& other) {
    name = new std::string(*(other.name));
    bonus = new int(*(other.bonus));
    territories = other.territories;
}


// Adds a territory to the current continent's territories vector.
void Continent::addTerritory(Territory* territory) {
    territories.push_back(territory);
}

//Basic getters
const std::vector<Territory*>& Continent::getTerritories() const {
    return territories;
}
int Continent::getBonus() const {
    return *bonus;
}
std::string Continent::getName() const {
    return *name;
}

//Assignment Operator
Continent& Continent::operator=(const Continent& other) {
    if (this == &other) return *this;
    delete name;
    delete bonus;
    name = new std::string(*(other.name));
    bonus = new int(*(other.bonus));
    territories = other.territories;
    return *this;
}

//Stream insertion Operator
std::ostream& operator<<(std::ostream& out, const Continent& continent) {
    out << "Continent Name: " << continent.getName() << ", Number of Armies: " << continent.getBonus();
    return out;
}


//---------------------------------Map----------------------------------
// Constructor for Map: Initializes the image, scroll, author, name, wrap, and warn.
Map::Map(const std::string& i, const std::string& s, const std::string& a, const std::string& n, bool wp, bool wn){
    image = new std::string(i);
    scroll = new std::string(s);
    author =  new std::string(a);
    name =  new std::string(n);
    wrap = new bool(wp);
    warn = new bool(wn);
}

// Destructor for Map: Deletes the dynamically allocated members and territories and continents vectors. This is where we delete territories and continent as well.
Map::~Map(){
    delete image;
    delete scroll;
    delete author;
    delete name;
    delete wrap;
    delete warn;
    image = nullptr;
    scroll = nullptr;
    author = nullptr;
    name = nullptr;
    wrap = nullptr;
    warn = nullptr;

    for (Territory* territory : territories){
        delete territory;
    }
    territories.clear();

    for (Continent* continent : continents){
        delete continent;
    }
    territories.clear();
}

// Copy constructor Just copying the pointers, not the territories and continents themselves as it doesn't make sense.
Map::Map(const Map& other) {
    image = new std::string(*(other.image));
    scroll = new std::string(*(other.scroll));
    author = new std::string(*(other.author));
    name = new std::string(*(other.name));
    wrap = new bool(*(other.wrap));
    warn = new bool(*(other.warn));

    territories = other.territories;
    continents = other.continents;
}


// Adds a territory to the map's territories vector.
void Map::addTerritory(Territory* territory){
    territories.push_back(territory);
}

// Adds a continent to the map's continents vector.
void Map::addContinent(Continent* continent){
    continents.push_back(continent);
}

// Basic getters
std::string Map::getImage() const{
    return *image;
}
std::string Map::getScroll() const{
    return *scroll;
}
std::string Map::getAuthor() const{
    return *author;
}
std::string Map::getName() const{
    return *name;
}
bool Map::getWrap() const {
    return *wrap;
}
bool Map::getWarn() const {
    return *warn;
}
const std::vector<Continent*>& Map::getContinents() const {
    return continents;
}

//Assignment Operator
Map& Map::operator=(const Map& other) {
    if (this == &other) return *this;
    delete image;
    delete scroll;
    delete author;
    delete name;
    delete wrap;
    delete warn;
    image = new std::string(*(other.image));
    scroll = new std::string(*(other.scroll));
    author = new std::string(*(other.author));
    name = new std::string(*(other.name));
    wrap = new bool(*(other.wrap));
    warn = new bool(*(other.warn));
    territories = other.territories;
    continents = other.continents;
    return *this;
}


//Stream insertion Operation
std::ostream& operator<<(std::ostream& out, const Map& map) {
    out << "Map Name: " << map.getName() << ", Author: " << map.getAuthor();
    return out;
}


//--------------------------------Map Validation Helper methods----------------------------------
// Depth-first search to visit territories and build the visited set.
void Map::dfs(Territory* start, std::unordered_set<Territory*>& visited) const {
    if (visited.find(start) != visited.end()) return;

    visited.insert(start);
    for (Territory* adjacent : start->getAdjacentTerritories()) {
        dfs(adjacent, visited);
    }
}

// Checks if all territories in the map are interconnected.
//Satisfies: 1) the map is a connected graph
bool Map::isConnected() const {
    if (territories.empty()) return true;
    
    std::unordered_set<Territory*> visited;
    dfs(territories[0], visited);

    return visited.size() == territories.size();
}

// Checks if all continents in the map are interconnected through their territories.
//Satisfies: 2) continents are connected subgraphs
bool Map::areContinentsInterconnected() const {
    if (continents.empty() || territories.empty()) return true;

    std::unordered_set<Territory*> visited;
    dfs(territories[0], visited);

    for (Continent* continent : continents) {
        bool continentVisited = false;

        for (Territory* territory : continent->getTerritories()) {
            if (visited.find(territory) != visited.end()) {
                continentVisited = true;
                break;
            }
        }

        if (!continentVisited) return false;
    }

    return true;
}

// Checks if territories are unique to continents.
//Satisfies: 3) each country belongs to one and only one continent
bool Map::areTerritoriesUniqueToContinents() const {
    std::unordered_set<Territory*> territoriesSet;

    for (Continent* continent : continents) {
        for (Territory* territory : continent->getTerritories()) {
            if (territoriesSet.find(territory) != territoriesSet.end()) return false;
            territoriesSet.insert(territory);
        }
    }
    return true;
}

// Determines the validity of the map.
bool Map::isValid() const {
    //std::cout << isConnected() << " " << areContinentsInterconnected() << " " << areTerritoriesUniqueToContinents() << " these were results\n";
    return isConnected() && areContinentsInterconnected() && areTerritoriesUniqueToContinents();
}

