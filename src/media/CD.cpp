#include "CD.h"
#include<iostream>
#include<fstream>
#include<string>

CD :: CD() : Media(){
    cout << "Duration : ";
    cin >> duration;

    cout << "Number of Tracks : ";
    cin >> nbTrack;

    cout << "Production Company : ";
    getline(cin, productionCompany);

    cout << "Tracks : " << endl;
    for(int i = 0; i < nbTrack; i++){
        string trackTitle;
        cout << "Track " << i+1 << " : ";
        getline(cin, trackTitle);
        tracksTitle.push_back(trackTitle);
    }
}

CD::CD(int id, string title, string author, string style, string _date,int _duration, int _nbTrack, string _tracksTitle[], string _productionCompany) : Media(id, title, author, style){
    duration = _duration;
    nbTrack = _nbTrack;
    for (int i = 0; i < _nbTrack; i++)
    {
        tracksTitle.push_back(_tracksTitle[i]);
    }
    productionCompany = _productionCompany;
}

CD::CD(string* parameters):Media(parameters)
{
    int taille = parameters->size();
    int x=1;
    while(x<5 && taille!=0){
        int pos = parameters->find(';');
        switch(x)
        {
            case 1: 
                duration = stoi(parameters->substr(0, pos));
                break;
            case 2: 
                nbTrack = stoi(parameters->substr(0, pos));
                break;
            case 3: 
                for (int i = 0; i < nbTrack; i++)
                {
                    pos = parameters->find(';');
                    tracksTitle.push_back(parameters->substr(0, pos));

                    // If it's not the last track
                    // This operation is done after the case also.
                    if(i < nbTrack-1){
                        *parameters = parameters->substr(pos+1, taille-(pos+1));
                        taille = parameters->size();
                    }
                    
                }
                break;
            case 4: 
                productionCompany = parameters->substr(0, pos);
                break;
        }
        x++;
        *parameters = parameters->substr(pos+1, taille-(pos+1));
        taille = parameters->size();
    }
}

int CD :: getDuration(){
    return duration;
}

int CD :: getNbTrack(){
    return nbTrack;
}

list<string> CD :: getTracksTitle(){
    return tracksTitle;
}

string CD :: getProductionCompany(){
    return productionCompany;
}

void CD::show(){
    cout<<"...CD..."<< getId() <<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Number of Tracks : "<<nbTrack<<endl;
    cout << "--- Tracks ---" << endl;
    // Display all tracks
    for(string tracksTitle : tracksTitle){
        cout<<"Track's Title : " << tracksTitle<<endl;
    }
    cout << "---------" << endl;
    cout<<"Prodution Company : "<<productionCompany<<endl;
}

string CD::toString(){
    string toString = "CD;";
    toString += Media::toString();
    toString += ";"+to_string(duration)+";"+to_string(nbTrack)+";";
    
    for(string tracksTitle : tracksTitle){
        toString = toString+tracksTitle+";";
    }
    toString += productionCompany;
    return toString;
}