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