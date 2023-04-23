#include "digitalRessources.h"
#include<iostream>
#include<fstream>
#include<string>

DigitalRessources :: DigitalRessources() : Media(){
    cout << "Type : ";
    cin >> type;
    cout << "Size : ";
    cin >> size;
    cout << "URL : ";
    cin >> url;
}

int DigitalRessources :: getSize(){
    return size;
}

string DigitalRessources :: getUrl(){
    return url;
}

string DigitalRessources :: getType(){
    return type;
}

void DigitalRessources::show(){
    cout<<"...DIGITAL RESSOURCES..."<<getId()<<endl;
    Media::show();
    cout<<"Type : "<<type<<endl;
    cout<<"Size : "<<size<<endl;
    cout<<"URL : "<<url<<endl;
}