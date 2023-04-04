#ifndef CD_H
#define CD_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class CD : public Media{
    public : 
    //constructeur
    CD(int id, string title, string author, string style, int _nbPages, string _date,int _duration, int _nbTrack, string _tracksTitle[], string _productionCompany) : Media(id, title, author, style){
        duration = _duration;
        nbTrack = _nbTrack;
        tracksTitle = _tracksTitle;
        productionCompany = _productionCompany;
    }
    //deconstructeur
    ~CD(){
    }

    //methodes
    int getDuration();
    int getNbTrack();
    string getTracksTitle();
    string getProductionCompany();
    void show();

    private : 
    //attributs
    int duration;
    int nbTrack;
    string tracksTitle[];
    string productionCompany;
};

#endif