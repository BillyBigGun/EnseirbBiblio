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
    void execute(Mediatheque Mediatheque, string param);

}; 

#endif