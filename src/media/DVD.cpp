#include "DVD.h"
#include<iostream>
#include<fstream>
#include<string>

DVD::DVD() : Media()
{
    string temp;
    cout << "Duration : ";
    getline(cin, temp);
    duration = stoi(temp);
    
    cout << "Number of Tracks : ";
    getline(cin, temp);
    nbTrack = stoi(temp);
    
    cout << "Tracks : " << endl;
    for(int i = 0; i < nbTrack; i++){
        string trackTitle;
        cout << "Track " << i+1 << " : ";
        getline(cin, trackTitle);
        tracksTitle.push_back(trackTitle);
    }
}

DVD::DVD(int id, string title, string author, string style,int _duration, int _nbTrack, string _tracksTitle[]): Media(id, title, author, style){
    duration= _duration;
    nbTrack = _nbTrack;
    for (int i = 0; i < _nbTrack; i++)
    {
        tracksTitle.push_back(_tracksTitle[i]);
    }
}

DVD::DVD(string* parameters):Media(parameters)
{
    int taille = parameters->size();
    int x=1;
    while(x<4 && taille!=0){
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
                for(int i = 0; i < nbTrack; i++){
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
        }
        x++;
        *parameters = parameters->substr(pos+1, taille-(pos+1));
        taille = parameters->size();
    }
}

int DVD :: getDuration(){
    return duration;
}

int DVD :: getNbTrack(){
    return nbTrack;
}

list<string> DVD :: getTracksTitle(){
    return tracksTitle;
}

void DVD::show(){
    cout<<"...DVD..."<<getId()<<endl;
    Media::show();
    cout<<"Duration : "<<duration<<endl;
    cout<<"Number of Tracks : "<<nbTrack<<endl;
    cout << "--- Tracks ---" << endl;
    for(string tracksTitle : tracksTitle){
        cout<<"Tracks : "<<tracksTitle<<endl;
    }
    cout << "---------" << endl;
}

string DVD::toString(){
    string toString = "DVD;";
    toString += Media::toString();
    toString += ";"+to_string(duration)+";"+to_string(nbTrack)+";";
    for(string trackTitle : tracksTitle){
        toString += trackTitle+";";
    }
    return toString;
}