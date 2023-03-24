#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class book : public Media{
    public : 
    //constructeur
    book(int _nbPages, string _date, string _collection, string _resume){
        nbPages = _nbPages;
        date = _date;
        collection = _collection;
        resume = _resume;
    }
    //deconstructeur
    ~book(){
    }

    //methodes
    int getNbPages();
    string getDate();
    string getCollection();
    string getResume();

    private:
    //attributs
    int nbPages;
    string date;
    string collection;
    string resume;

};