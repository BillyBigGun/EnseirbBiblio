#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class VHS : public Media{
    public : 
    //constructeur
    VHS(int duration, string production){
        duration = _duration;
        production = _production;
    }
    //deconstructeur
    ~VHS(){
    }
    //methodes
    int getDuration();
    int getProduction();

    private :
    //attributs
    int duration;
    string production;

};