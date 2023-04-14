#ifndef DELETE_COMMAND_H
#define DELETE_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

using namespace std;

class DeleteCommand : public Command{
    
    public:
    DeleteCommand():Command(){}
    ~DeleteCommand()=default;

    void execute(Mediatheque* mediatheque, string id);

};

#endif