#ifndef DVD_H
#define DVD_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class DVD : public Media{
    public : 
    //constructeur
    DVD(){};
    DVD(int id, string title, string author, string style,int _duration, int _nbTrack, string _tracksTitle): Media(id, title, author, style){
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
    void show();

    private : 
    //attributs
    int duration;
    int nbTrack;
    string tracksTitle;
};

#endif