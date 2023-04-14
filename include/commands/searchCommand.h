#ifndef SEARCH_COMMAND_H
#define SEARCH_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "mediatheque.h"
#include "command.h"

using namespace std;

class SearchCommand : public Command{
    
    public:
    SearchCommand():Command(){}
    ~SearchCommand()=default;

    void execute(Mediatheque mediatheque, string type);

};

#endif