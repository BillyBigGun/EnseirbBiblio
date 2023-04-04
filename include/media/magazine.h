#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "book.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Magasine : public Book{
    public : 
    //constructeur
    Magasine(int id, string title, string author, string style,int _nbArticles, string _articles[], string _editor): Media(id, title, author, style){
        nbArticles = _nbArticles;
        articles = _articles;
        editor = _editor;
    }
    //deconstructeur
    ~Magasine(){
    }
    //methodes
    int getNbArticles();
    string getArticles();
    string getEditor();
    void show();

    private :
    //attributs
    int nbArticles;
    string articles[];
    string editor;

};

#endif