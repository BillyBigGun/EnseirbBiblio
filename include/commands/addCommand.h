#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "mediatheque.h"
#include "command.h"

using namespace std;

class AddCommand : public Command{
    
    public:
    AddCommand():Command(){}
    ~AddCommand()=default;

    void execute(Mediatheque mediatheque, string type);

};

#endif