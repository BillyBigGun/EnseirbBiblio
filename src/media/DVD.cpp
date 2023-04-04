#include "DVD.h"
#include<iostream>
#include<fstream>
#include<string>

int DVD :: getDuration(){
    return duration;
}

int DVD :: getNbTrack(){
    return nbTrack;
}

string DVD :: getTracksTitle(){
    return tracksTitle;
}

void DVD::show(){
    cout<<"...DVD..."<<id<<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Number of Tracks : "<<nbTrack<<endl;
    cout<<"Track's Title : "<<tracksTitle<<endl;
}