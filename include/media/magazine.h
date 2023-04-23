#ifndef MAGAZINE_H
#define MAGAZINE_H

#include "book.h"
#include<iostream>
#include<fstream>
#include<string>
#include <list>

using namespace std;

class Magasine : public Media{
    public : 
    //constructeur
    Magasine();

    Magasine(int id, string title, string author, string style,int _nbPages, string _date, string _collection, string _resume, int _nbArticles, string _articles[], string _editor): Media(id, title, author, style){
        nbArticles = _nbArticles;
        for (int i = 0; i < _nbArticles; i++)
        {
            articles.push_back(_articles[i]);
        }
        editor = _editor;
    }
    //deconstructeur
    ~Magasine()override=default;

    //methodes
    int getNbArticles();
    list<string> getArticles();
    string getEditor();
    void show() override;

    private :
    //attributs
    int nbArticles;
    list<string> articles;
    string editor;

};

#endif