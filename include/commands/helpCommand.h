#ifndef HELP_COMMAND_H
#define hELP_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class HelpCommand : public Command{
    
    public:
    HelpCommand():Command(){}
    ~HelpCommand()=default;

    void execute(Mediatheque* mediatheque, string id);

};

#endif