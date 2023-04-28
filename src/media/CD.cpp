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
    cin >> productionCompany;
    cout << "Tracks : " << endl;
    for(int i = 0; i < nbTrack; i++){
        string trackTitle;
        cout << "Track " << i+1 << " : ";
        cin >> trackTitle;
        tracksTitle.push_back(trackTitle);
    }
}

CD::CD(string parameters)
{
    parameters = Media::Media(parameters);
    while(x<5 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: duration = parameters.substr(0, pos);
            case 2: nbTrack = parameters.substr(0, pos);
            case 3: productionCompany = parameters.substr(0, pos);
            case 4: trackTitle = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
    }
    return parameters;
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
    string toString = 'CD;';
    toString += Media.toString();
    return toString+";"+duration+";"+nbTrack+";"+tracksTitle+";"+productionCompany;
}