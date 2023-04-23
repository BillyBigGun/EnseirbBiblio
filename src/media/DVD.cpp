#include "DVD.h"
#include<iostream>
#include<fstream>
#include<string>

DVD::DVD() : Media(){
    cout << "Duration : ";
    cin >> duration;
    cout << "Number of Tracks : ";
    cin >> nbTrack;
    cout << "Tracks : " << endl;
    for(int i = 0; i < nbTrack; i++){
        string trackTitle;
        cout << "Track " << i+1 << " : ";
        cin >> trackTitle;
        tracksTitle.push_back(trackTitle);
    }
}

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