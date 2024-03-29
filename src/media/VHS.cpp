#include "VHS.h"
#include<iostream>
#include<fstream>
#include<string>

VHS::VHS() : Media(){
    string temp;
    cout << "Duration : ";
    getline(cin, temp);
    duration = stoi(temp);
    
    cout << "Production Company : ";
    getline(cin, production);
}

VHS::VHS(int id, string title, string author, string style,int _duration, string _production): Media(id, title, author, style){
    duration = _duration;
    production = _production;
}

VHS::VHS(string* parameters):Media(parameters)
{
    int taille = parameters->size();
    int x=1;
    while(x<3 && taille!=0){
        int pos = parameters->find(';');
        switch(x)
        {
            case 1: 
                duration = stoi(parameters->substr(0, pos));
                break;
            case 2: 
                production = parameters->substr(0, pos);
                break;
        }
        x++;
        *parameters = parameters->substr(pos+1, taille-(pos+1));
        taille = parameters->size();
    }
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
    string toString = "VHS;";
    toString += Media::toString();
    return toString+";"+to_string(duration)+";"+production;
}