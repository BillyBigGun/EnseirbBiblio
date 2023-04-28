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

DigitalRessources::DigitalRessources(string parameters)
{
    parameters = Media::Media(parameters);
    while(x<4 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: type = parameters.substr(0, pos);
            case 2: size = parameters.substr(0, pos);
            case 3: url = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
    }
    return parameters;
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

string DigitalRessources::toString(){
    string toString = 'DigitalRessources;';
    toString += Media.toString();
    return toString+";"+type+";"+size+";"+url;
}