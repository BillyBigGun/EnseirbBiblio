#ifndef CD_H
#define CD_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>
#include <list>

using namespace std;

class CD : public Media{
    public : 
    //constructeur
    CD(); //constructeur par defaut
    
    CD(int id, string title, string author, string style, string _date,int _duration, int _nbTrack, string _tracksTitle[], string _productionCompany);
    CD(string parameters);
    
    //deconstructeur
    ~CD() override=default;

    //methodes
    int getDuration();
    int getNbTrack();
    list<string> getTracksTitle();
    string getProductionCompany();
    void show() override;
    string toString() override;

    private : 
    //attributs
    int duration;
    int nbTrack;
    list<string> tracksTitle;
    string productionCompany;
};

#endif