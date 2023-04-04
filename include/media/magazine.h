#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "book.h"
#include<iostream>
#include<fstream>
#include<string>
#include <list>

using namespace std;

class Magasine : public Book{
    public : 
    //constructeur
    Magasine(int id, string title, string author, string style,int _nbPages, string _date, string _collection, string _resume, int _nbArticles, string _articles[], string _editor): Book(id, title, author, style, _nbPages, _date, _collection, _resume){
        nbArticles = _nbArticles;
        for (int i = 0; i < _nbArticles; i++)
        {
            articles.push_back(_articles[i]);
        }
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
    list<string> articles;
    string editor;

};

#endif