#include "VHS.h"
#include<iostream>
#include<fstream>
#include<string>

int VHS :: getDuration(){
    return duration;
}

string VHS :: getProduction(){
    return production;
}

void VHS::show(){
    cout<<"...VHS..."<<id<<endl;
    Media::show();
    cout<<"Duration : "<<Duration<<endl;
    cout<<"Prodution Company : "<<production<<endl;
}