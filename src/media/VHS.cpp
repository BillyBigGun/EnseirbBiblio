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

VHS::VHS(string parameters)
{
    parameters = Media::Media(parameters);
    while(x<3 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: duration = parameters.substr(0, pos);
            case 2: production = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
    }
    return parameters;
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

string VHS::toString(){
    string toString = 'VHS;';
    return toString+";"+duration+";"+production;
}