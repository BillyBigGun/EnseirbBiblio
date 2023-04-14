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

list<string> DVD :: getTracksTitle(){
    return tracksTitle;
}

void DVD::show(){
    cout<<"...DVD..."<<getId()<<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Number of Tracks : "<<nbTrack<<endl;
    cout << "--- Tracks ---" << endl;
    for(string tracksTitle : tracksTitle){
        cout<<"Tracks : "<<tracksTitle<<endl;
    }
    cout << "---------" << endl;
}