#ifndef ADD_COMMAND_H
#define ADD_COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "command.h"

#include "media.h"
#include "book.h"
#include "CD.h"
#include "digitalRessources.h"
#include "DVD.h"
#include "magazine.h"
#include "VHS.h"

using namespace std;

class AddCommand : public Command{
    
    public:
    AddCommand():Command(){}
    ~AddCommand()=default;

    //void execute(Mediatheque mediatheque, string type);

    // private:
    // string mediaTypesString [6]= {"BOOK", "CD", "DIGIGTAL_RESSOURCES", "DVD", "MAGASINE", "VHS"};
    // type mediaTypes [6] = {book, CD, digitalRessources, DVD, magasine, VHS};

};

#endif