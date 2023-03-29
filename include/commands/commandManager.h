#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "mediatheque.h"
#include "command.h"
#include "addCommand.h"

using namespace std;

class CommandManager{

private:
    Mediatheque mediatheque;
    map<string, Command*> commands;

public:
    CommandManager();

    ~CommandManager()=default;
    
    void executeCommand(string command);
};



#endif