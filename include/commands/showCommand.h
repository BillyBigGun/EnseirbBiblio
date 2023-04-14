#ifndef SHOW_COMMAND_H
#define SHOW_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "mediatheque.h"
#include "command.h"

using namespace std;

class ShowCommand : public Command{
    
    public:
    ShowCommand():Command(){}
    ~ShowCommand()=default;

    void execute(Mediatheque* mediatheque, string id);

};

#endif