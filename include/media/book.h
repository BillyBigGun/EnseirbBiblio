#ifndef BOOK_H
#define BOOK_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Book : public Media{
    public : 
    //constructeur
    Book(int id, string title, string author, string style, int _nbPages, string _date, string _collection, string _resume) : Media(id, title, author, style) {
        nbPages = _nbPages;
        date = _date;
        collection = _collection;
        resume = _resume;
    }
    //deconstructeur
    ~Book(){
    }

    //methodes
    int getNbPages();
    string getDate();
    string getCollection();
    string getResume();
    void show();

    private:
    //attributs
    int nbPages;
    string date;
    string collection;
    string resume;

};

#endif