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
    cout<<"...VHS..."<<getId()<<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Prodution Company : "<<production<<endl;
}