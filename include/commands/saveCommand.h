#ifndef SAVE_COMMAND_H
#define SAVE_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class SaveCommand : public Command{
    
    public:
    SaveCommand():Command(){}
    ~SaveCommand()=default;

    void execute(Mediatheque mediatheque, string filename);

};

#endif