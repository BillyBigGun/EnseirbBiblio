#include "VHS.h"
#include<iostream>
#include<fstream>
#include<string>

VHS::VHS() : Media(){
    cout << "Duration : ";
    cin >> duration;
    cout << "Production Company : ";
    cin >> production;
}

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