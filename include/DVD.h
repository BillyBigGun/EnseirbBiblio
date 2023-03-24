#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class DVD : public Media{
    public : 
    //constructeur
    DVD(int _duration, int _nbTrack, string _tracksTitle){
        duration= _duration;
        nbTrack = _nbTrack;
        tracksTitle = _tracksTitle;
    }
    //deconstructeur
    ~DVD(){
    }
    //methodes
    int getDuration();
    int getNbTrack();
    string getTracksTitle();

    private : 
    //attributs
    int duration;
    int nbTrack;
    string tracksTitle;
};