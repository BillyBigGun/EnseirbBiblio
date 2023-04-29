#ifndef DIGITAL_RESSOURCES_H
#define DIGITAL_RESSOURCES_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class DigitalRessources : public Media{
    public : 
    DigitalRessources();
    //constructeur
    DigitalRessources(int id, string title, string author, string style,int _size, string _url, string _type);
    DigitalRessources(string* parameters);
    //deconstructeur
    ~DigitalRessources() override=default;

    //methodes
    int getSize();
    string getUrl();
    string getType();
    void show() override;
    string toString() override;


    private : 
    //attributs
    int size;
    string url;
    string type;

};

#endif