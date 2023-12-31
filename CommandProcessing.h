#pragma once

#include "GameEngine.h"
#include <vector>
#include <string>
#include <ostream>
#include <fstream>
#include <exception>

#include "LoggingObserver.h"

using std::string;
using std::vector;

enum class GameStateType;

string getFirstSubstring(const string& string);

class Command : public ILoggable, public Subject {
private:
    string *_command;
    string *_effect;

public:
    // default constructor
    Command();

    // constructor that only takes one parameter
    Command(string &command);

    // Non default constructor
    Command(string &command, string &effect);

    // Copy Constructor
    Command(const Command &cm);

    // destructor
    ~Command();

    // Assignment operator
    Command& operator=(const Command &rhs);

    // Stream ingestion operator
    friend std::ostream& operator<<(std::ostream& out, const Command &command);

    string& getCommand();

    void saveEffect(const string& effect);

    string& getCommandEffect();

    // method for game logs
    string stringToLog() override;

    // method for tournament logs
    string stringToTourLog(int game) override;
};

class TournamentConfiguration {
private:
    int *_numberOfGames;
    int *_maxTurns;
    vector<string> *_mapFiles;
    vector<string> *_playerStrategies;

public:
    // non default constructor
    TournamentConfiguration(int &numberOfGames, int &maxTurns, vector<string> &mapsFiles, vector<string> &playerStrategies);

    // copy constructor
    TournamentConfiguration(const TournamentConfiguration &tc);

    // destructor
    ~TournamentConfiguration();

    // Assignment operator
    TournamentConfiguration& operator=(const TournamentConfiguration &rhs);

    // Stream ingestion operator
    friend std::ostream& operator<<(std::ostream& out, const TournamentConfiguration &tc);

    // getters
    int& getNumberOfGames();
    int& getMaxTurns();
    vector<string>& getMapsFiles();
    vector<string>& getPlayerStrategies();

    // method that validates and parses the parameters of the tournament command
    static TournamentConfiguration* validateAndParseCommand(string command);
};

class CommandProcessor : public ILoggable, public Subject {

private:
    std::vector<Command*> *_commands;

    virtual string& readCommand();

    Command& saveCommand(string& command);

public:
    CommandProcessor();

    // Copy constructor
    CommandProcessor(const CommandProcessor &commandProcessor);

    // Destructor
    ~CommandProcessor();

    // Assignment operator
    CommandProcessor& operator=(const CommandProcessor &rhs);

    // Stream ingestion operator
    friend std::ostream& operator<<(std::ostream& out, const CommandProcessor &cp);

    Command& getCommand();

    bool validate(Command& command, GameStateType gameState);

    string stringToLog() override;

    string stringToTourLog(int game) override;
};

class FileLineReader {

private:
    std::ifstream *_fileStream;

public:
    // default constructor
    FileLineReader();

    // non default constructor
    FileLineReader(const string& filePath);

    /// destructor
    ~FileLineReader();

    // no assignment operator or copy constructor can be added to this class because stream objects cannot be copied

    // Stream ingestion operator
    friend std::ostream& operator<<(std::ostream& out, const FileLineReader &flr);

    // reads next line from the file
    string& readLineFromFile();
};

class FileCommandProcessorAdapter : public CommandProcessor {

private:
    FileLineReader *_fileLineReader;

public:
    // default constructor
    FileCommandProcessorAdapter();

    // non default constructor
    FileCommandProcessorAdapter(const string& filePath);

    // copy constructor
    FileCommandProcessorAdapter(const FileCommandProcessorAdapter& fcp);

    // destructor
    ~FileCommandProcessorAdapter();

    // Assignment operator
    FileCommandProcessorAdapter& operator=(const FileCommandProcessorAdapter &rhs);

    // Stream ingestion operator
    friend std::ostream& operator<<(std::ostream& out, const FileCommandProcessorAdapter &fcp);

    // this method reads the next command from the file
    string& readCommand();
};