#include "digitalRessources.h"
#include<iostream>
#include<fstream>
#include<string>

int digitalRessources :: getSize(){
    return size;
}

string digitalRessources :: getUrl(){
    return url;
}

string digitalRessources :: getType(){
    return type;
}

void digitalRessources::show(){
    cout<<"...DIGITAL RESSOURCES..."<<id<<endl;
    Media::show();
    cout<<"Type : "<<type<<endl;
    cout<<"Size : "<<size<<endl;
    cout<<"URL : "<<url<<endl;
}