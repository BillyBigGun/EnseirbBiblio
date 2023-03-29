#include "book.h"
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class magasine : public book{
    public : 
    //constructeur
    magasine(int _nbArticles, string _articles[], string _editor){
        nbArticles = _nbArticles;
        articles = _articles;
        editor = _editor;
    }
    //deconstructeur
    ~magasine(){
    }
    //methodes
    int getNbArticles();
    string getArticles();
    string getEditor();

    private :
    //attributs
    int nbArticles;
    string articles[];
    string editor;

};