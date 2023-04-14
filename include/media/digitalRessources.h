#ifndef DIGITAL_RESSOURCES_H
#define DIGITAL_RESSOURCES_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class digitalRessources : public Media{
    public : 
    digitalRessources(){
        
    }
    //constructeur
    digitalRessources(int id, string title, string author, string style,int _size, string _url, string _type): Media(id, title, author, style){
        size = _size;
        url = _url;
        type = _type;
    }
    //deconstructeur
    ~digitalRessources(){
    }

    //methodes
    int getSize();
    string getUrl();
    string getType();
    void show();


    private : 
    //attributs
    int size;
    string url;
    string type;

};

#endif