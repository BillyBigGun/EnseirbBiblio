#ifndef VHS_H
#define VHS_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class VHS : public Media{
    public : 
    //constructeur
    VHS();
    VHS(int id, string title, string author, string style,int _duration, string _production);
    VHS(string parameters);
    //deconstructeur
    ~VHS()override=default;
    //methodes
    int getDuration();
    string getProduction();
    void show() override;
    string toString() override;

    private :
    //attributs
    int duration;
    string production;

};

#endif