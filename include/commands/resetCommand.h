#ifndef RESET_COMMAND_H
#define RESET_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class ResetCommand : public Command{
    
    public:
    ResetCommand():Command(){}
    ~ResetCommand()=default;

    //void execute(Mediatheque mediatheque, string type);

};

#endif