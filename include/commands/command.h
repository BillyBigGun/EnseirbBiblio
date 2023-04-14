#ifndef COMMAND_H
#define COMMAND_H

#include<iostream>
#include<fstream>
#include<string>

#include "mediatheque.h"

using namespace std;

class Command{
    public : 
    //constructeur
    Command(){

    }
    //deconstructeur
    ~Command()=default;

    //methodes
    virtual void execute(Mediatheque* Mediatheque, string param =NULL);

}; 

#endif