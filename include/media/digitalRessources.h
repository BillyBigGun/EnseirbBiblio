#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class digitalRessources : public Media{
    public : 
    //constructeur
    digitalRessources(int _size, string _url, string _type){
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


    private : 
    //attributs
    int size;
    string url;
    string type;

};