#include "PlayerStrategies.h"


#include "map.h"
#include <iostream>
#include "Player.h"
#include "Cards.h"
#include "GameEngine.h"

// --------------- PlayerStrategy class ---------------

// Default Constructor
PlayerStrategy::PlayerStrategy() 
{
	m_strategyType = StrategyType::None;
}

// Params Constructor
PlayerStrategy::PlayerStrategy(Player* player)
	: m_player(player)
{
	m_strategyType = StrategyType::None;
}

// Copy Constructor
PlayerStrategy::PlayerStrategy(PlayerStrategy& other)
{
	m_strategyType = other.m_strategyType;
	m_player = other.m_player;
}

// Assignment operator
PlayerStrategy& PlayerStrategy::operator=(const PlayerStrategy& other)
{
	m_strategyType = other.m_strategyType;
	m_player = other.m_player;

	return *this;
}

// Player pointer getter
const Player* PlayerStrategy::getPlayer()
{
	return m_player;
}

// Strategy type getter
const StrategyType PlayerStrategy::getStrategyType()
{
	return m_strategyType;
}

// Stream insertion operator
std::ostream& operator<<(std::ostream& os, const PlayerStrategy& strategy)
{

	// Switch based on the strategy enum type and print 
	switch (strategy.m_strategyType)
	{
	case StrategyType::HumanPlayer:
		os << " this is a Human Player Strategy!";
		break;
	case StrategyType::AggressivePlayer:
		os << " this is a AggressivePlayer Strategy!";
		break;
	case StrategyType::BenevolentPlayer:
		os << " this is a BenevolentPlayer Strategy!";
		break;
	case StrategyType::NeutralPlayer:
		os << " this is a NeutralPlayer Strategy!";
		break;
	case StrategyType::CheaterPlayer:
		os << " this is a CheaterPlayer Strategy!";
		break;

	default:
		os << "ERROR: Invalid strategy type!";
		break;
	}

	return os;
}

// --------------- HumanPlayerStrategy class ---------------

// Constructor
HumanPlayerStrategy::HumanPlayerStrategy(Player* player)
	: PlayerStrategy(player)
{
	m_strategyType = (StrategyType::HumanPlayer);	
}

void HumanPlayerStrategy::issueOrder(const std::string& orderType, Territory* source, Territory* target, int* num, Player* targetPlayer, Deck* deck, GameEngine* gameEngine)
{
	m_player->issueOrder(orderType, source, target, num, targetPlayer, deck, gameEngine);
}

std::vector<Territory*> HumanPlayerStrategy::toAttack()
{
    return m_player->toAttack();
}

std::vector<Territory*> HumanPlayerStrategy::toDefend()
{
    return m_player->toDefend();
}

// --------------- AggressivePlayerStrategy class ---------------

// Constructor
AggressivePlayerStrategy::AggressivePlayerStrategy(Player* player) 
	: PlayerStrategy(player)
{
	m_strategyType = (StrategyType::AggressivePlayer);
}

void AggressivePlayerStrategy::issueOrder(const std::string& orderType, Territory* source, Territory* target, int* num, Player* targetPlayer, Deck* deck, GameEngine* gameEngine)
{
    m_player->issueOrder(orderType, source, target, num, targetPlayer, deck, gameEngine);
}

std::vector<Territory*> AggressivePlayerStrategy::toAttack()
{
    return m_player->toAttack();
}

std::vector<Territory*> AggressivePlayerStrategy::toDefend()
{
    return m_player->toDefend();
}

// --------------- BenevolentPlayerStrategy class ---------------

// Constructor
BenevolentPlayerStrategy::BenevolentPlayerStrategy(Player* player)
{
	m_strategyType = (StrategyType::BenevolentPlayer);
}

// Shouldn't be able to issue a Bomb order so remove Bomb order as an option
void BenevolentPlayerStrategy::issueOrder(const std::string& orderType, Territory* source, Territory* target, int* num, Player* targetPlayer, Deck* deck, GameEngine* gameEngine)
{
    m_player->issueOrder(orderType, source, target, num, targetPlayer, deck, gameEngine);
}

std::vector<Territory*> BenevolentPlayerStrategy::toAttack()
{
    return m_player->toAttack();
}

std::vector<Territory*> BenevolentPlayerStrategy::toDefend()
{
    return m_player->toDefend();
}


// --------------- NeutralPlayerStrategy class ---------------

// Constructor
NeutralPlayerStrategy::NeutralPlayerStrategy(Player* player)
{
	m_strategyType = (StrategyType::NeutralPlayer);
}

void NeutralPlayerStrategy::issueOrder(const std::string& orderType, Territory* source, Territory* target, int* num, Player* targetPlayer, Deck* deck, GameEngine* gameEngine)
{
}

std::vector<Territory*> NeutralPlayerStrategy::toAttack()
{
    return m_player->toAttack();
}

std::vector<Territory*> NeutralPlayerStrategy::toDefend()
{
    return m_player->toDefend();
}

// --------------- CheaterPlayerStrategy class ---------------

// Constructor
CheaterPlayerStrategy::CheaterPlayerStrategy(Player* player)
{
	m_strategyType = (StrategyType::CheaterPlayer);
}

void CheaterPlayerStrategy::issueOrder(const std::string& orderType, Territory* source, Territory* target, int* num, Player* targetPlayer, Deck* deck, GameEngine* gameEngine)
{
    m_player->issueOrder(orderType, source, target, num, targetPlayer, deck, gameEngine);
}

std::vector<Territory*> CheaterPlayerStrategy::toAttack()
{
    return m_player->toAttack();
}

std::vector<Territory*> CheaterPlayerStrategy::toDefend()
{
    return m_player->toDefend();
}


