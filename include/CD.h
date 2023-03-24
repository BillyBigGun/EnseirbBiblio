#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class CD : public Media{
    public : 
    //constructeur
    CD(int _duration, int _nbTrack, string _tracksTitle[], string _productionCompany){
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

    private : 
    //attributs
    int duration;
    int nbTrack;
    string tracksTitle[];
    string productionCompany;
};
