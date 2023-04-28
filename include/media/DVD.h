#ifndef DVD_H
#define DVD_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>
#include<list>

using namespace std;

class DVD : public Media{
    public : 
    //constructeur
    DVD();
    DVD(int id, string title, string author, string style,int _duration, int _nbTrack, string _tracksTitle[]): Media(id, title, author, style);
    //deconstructeur
    ~DVD() override=default;
    //methodes
    int getDuration();
    int getNbTrack();
    list<string> getTracksTitle();
    void show() override;
    string toString() override;

    private : 
    //attributs
    int duration;
    int nbTrack;
    list<string> tracksTitle;
};

#endif