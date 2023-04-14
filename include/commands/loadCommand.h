#ifndef LOAD_COMMAND_H
#define LOAD_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class LoadCommand : public Command{
    
    public:
    LoadCommand():Command(){}
    ~LoadCommand()=default;

    void execute(Mediatheque mediatheque, string filename);

};

#endif