#ifndef CLEAR_COMMAND_H
#define CLEAR_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class ClearCommand : public Command{
    
    public:
    ClearCommand():Command(){}
    ~ClearCommand()=default;

    void execute(Mediatheque mediatheque, string type);

};

#endif