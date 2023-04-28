#ifndef BOOK_H
#define BOOK_H

#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Book : public Media{
    public : 
    Book();
    //constructeur
    Book(int id, string title, string author, string style, int _nbPages, string _date, string _collection, string _resume);
    //deconstructeur
    ~Book() override=default;

    //methodes
    int getNbPages();
    string getDate();
    string getCollection();
    string getResume();
    void show() override;
    string toString() override;

    private:
    //attributs
    int nbPages;
    string date;
    string collection;
    string resume;

};

#endif