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