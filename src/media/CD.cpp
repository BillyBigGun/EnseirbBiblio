#include "CD.h"
#include<iostream>
#include<fstream>
#include<string>


int CD :: getDuration(){
    return duration;
}

int CD :: getNbTrack(){
    return nbTrack;
}

list<string> CD :: getTracksTitle(){
    return tracksTitle;
}

string CD :: getProductionCompany(){
    return productionCompany;
}

void CD::show(){
    cout<<"...CD..."<< getId() <<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Number of Tracks : "<<nbTrack<<endl;
    cout << "--- Tracks ---" << endl;
    // Display all tracks
    for(string tracksTitle : tracksTitle){
        cout<<"Track's Title : " << tracksTitle<<endl;
    }
    cout << "---------" << endl;
    cout<<"Prodution Company : "<<productionCompany<<endl;
}