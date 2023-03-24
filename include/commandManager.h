#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "mediatheque.h"

using namespace std;

class CommandManager{

private:
    Mediatheque mediatheque;

public:
    CommandManager();
    
    void executeCommand(string command);
};



#endif