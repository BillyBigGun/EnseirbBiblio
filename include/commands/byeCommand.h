#ifndef BYE_COMMAND_H
#define BYE_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class ByeCommand : public Command{
    
    public:
    ByeCommand():Command(){}
    ~ByeCommand()=default;

    void execute(Mediatheque* mediatheque, string type);

};

#endif