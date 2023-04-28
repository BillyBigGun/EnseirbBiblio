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

DigitalRessources::DigitalRessources(int id, string title, string author, string style,int _size, string _url, string _type): Media(id, title, author, style){
    size = _size;
    url = _url;
    type = _type;
}

DigitalRessources::DigitalRessources(string parameters):Media(&parameters)
{
    int taille = parameters.size();
    int x = 1;
    while(x<4 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: type = parameters.substr(0, pos);
            case 2: size = stoi(parameters.substr(0, pos));
            case 3: url = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
        int taille = parameters.size();
    }
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
    string toString = "DigitalRessources;";
    toString += Media::toString();
    return toString+";"+type+";"+to_string(size)+";"+url;
}