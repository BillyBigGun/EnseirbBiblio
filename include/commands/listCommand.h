#ifndef LIST_COMMAND_H
#define LIST_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class ListCommand : public Command{
    
    public:
    ListCommand():Command(){}
    ~ListCommand()=default;

    //void execute(Mediatheque mediatheque, string type);

};

#endif