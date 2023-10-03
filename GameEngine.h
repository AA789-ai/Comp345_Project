#pragma once

#include <memory>
#include <map>
#include <string>

using std::string;
using std::ostream;

namespace warzone
{
    // Enum representing valid game states
    enum GameStateType
    {
        START,
        MAP_LOADED,
        MAP_VALIDATED,
        PLAYERS_ADDED,
        ASSIGN_REINFORCEMENT,
        ISSUE_ORDERS,
        EXECUTE_ORDERS,
        WIN,
        END
    };

    // functions used for printing game messages and reading use commands from standard in
    void printInvalidCommandError();
    void printRemainingInStateMessage(string name);
    string getUserCommand();

    class GameEngine;

    // represents a base class for game states
    class GameState
    {
    protected:
        // attributes
        string _name;
        GameStateType _gameStateID;
        GameEngine &_gameEngine;
    public:
        // constructors
        explicit GameState(GameEngine &gameEngine,
                           GameStateType gameStateId,
                           string name);

        explicit GameState(GameState &gameState);

        // Assignment operator
        void operator=(const GameState &gameState);

        // destructor
        virtual ~GameState() {};

        // stream ingestion operator
        friend ostream & operator << (ostream &out, GameState &state);
        
        // method that returns the Id of the game state
        GameStateType getGameStateId();
        
        // method for entering the game state
        void enter();

        // method for updating the game state
        virtual void update() {};
    };

    // class representing the game engine
    class GameEngine
    {

    protected:
        // All GameStates of the game
        std::map<GameStateType, std::shared_ptr<GameState > > _gameStates;
        // The current GameState.
        GameState *_currentGameState;

    public:
        // constructor 
        GameEngine();

        GameEngine(GameEngine &engine);

        // Stream ingestion operator
        friend ostream & operator << (ostream &out, GameEngine &gameEngine);

        // Assignment operator
        void operator=(const GameEngine &gameEngine);

        // Get game state instance by ID
        GameState &getGameState(GameStateType gameStateID);

        // Get current GameState
        GameState &getCurrentGameState();

        // Register a new GameState to the game engine
        // since this is a template function, the implementation can only reside in the header file
        template <typename S>
        void registerGameState(GameStateType gameStateID) {
            _gameStates[gameStateID] = std::unique_ptr<S>(new S(*this));
        };

        // Change the current game state
        void setCurrentGameState(GameStateType gameStateID);

        // Call the update method on the current game state instance
        void update();

    protected: 
        // Sets the current game state
        void setCurrentGameState(GameState *gameState);
    };

    // Class representing the State state
    class StartState : public GameState
    {
    public:
        StartState(GameEngine &gameEngine);

        void update();
    };

    // Class MapLoadedState the State state
    class MapLoadedState : public GameState
    {
    public:
        MapLoadedState(GameEngine &gameEngine);

        void update();
    };

    // Class MapValidatedState the State state
    class MapValidatedState : public GameState
    {
    public:
        MapValidatedState(GameEngine &gameEngine);

        void update();
    };

    // Class PlayersAddedState the State state
    class PlayersAddedState : public GameState
    {
    public:
        PlayersAddedState(GameEngine &gameEngine);

        void update();
    };

    // Class AssignReinforcementState the State state
    class AssignReinforcementState : public GameState
    {
    public:
        AssignReinforcementState(GameEngine &gameEngine);

        void update();
    };

    // Class IssueOrdersState the State state
    class IssueOrdersState : public GameState
    {
    public:
        IssueOrdersState(GameEngine &gameEngine);

        void update();
    };

    // Class ExecuteOrdersState the State state
    class ExecuteOrdersState : public GameState
    {
    public:
        ExecuteOrdersState(GameEngine &gameEngine);

        void update();
    };

    // Class WinState the State state
    class WinState : public GameState
    {
    public:
        WinState(GameEngine &gameEngine); 

        void update();
    };

    // Class EndState the State state
    class EndState : public GameState
    {
    public:
        EndState(GameEngine &gameEngine);

        void update();
    };
};