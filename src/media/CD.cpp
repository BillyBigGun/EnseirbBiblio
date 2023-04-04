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

string CD :: getTracksTitle(){
    return tracksTitle;
}

string CD :: getProductionCompany(){
    return productionCompany;
}

void CD::show(){
    cout<<"...CD..."<<id<<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Number of Tracks : "<<nbTrack<<endl;
    cout<<"Track's Title : "<<tracksTitle<<endl;
    cout<<"Prodution Company : "<<productionCompany<<endl;
}