#ifndef COMMAND_MANAGER_H
#define COMMAND_MANAGER_H

#include <iostream>
#include <fstream>
#include <string>

#include "mediatheque.h"

#include "command.h"
#include "addCommand.h"
#include "byeCommand.h"
#include "clearCommand.h"
#include "deleteCommand.h"
#include "helpCommand.h"
#include "listCommand.h"
#include "loadCommand.h"
#include "resetCommand.h"
#include "saveCommand.h"
#include "searchCommand.h"
#include "showCommand.h"


using namespace std;

class CommandManager{

private:
    Mediatheque mediatheque;
    
protected:
    map<string, Command*> commands;

public:
    CommandManager();

    ~CommandManager()=default;
    
    void executeCommand(string command);

    void addMedia(Media* media);
    
};



#endif