#include "magazine.h"
#include<iostream>
#include<fstream>
#include<string>

Magasine::Magasine() : Book(){
    cout << "Number of Articles : ";
    cin >> nbArticles;
    cout << "Articles : " << endl;
    for(int i = 0; i < nbArticles; i++){
        string article;
        cout << "Article " << i+1 << " : ";
        cin >> article;
        articles.push_back(article);
    }
    cout << "Editor : ";
    cin >> editor;
}

Magasine::Magasine(int id, string title, string author, string style,int _nbPages, string _date, string _collection, string _resume, int _nbArticles, string _articles[], string _editor): Book(id, title, author, style, _nbPages, _date, _collection, _resume){
    nbArticles = _nbArticles;
    for (int i = 0; i < _nbArticles; i++)
    {
        articles.push_back(_articles[i]);
    }
    editor = _editor;
}

Magasine::Magasine(string parameters):Book(&parameters)
{
    int taille = parameters.size();
    int x=1;
    while(x<4 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: nbArticles = stoi(parameters.substr(0, pos));
            case 2: 
                for(int i = 0; i < nbArticles; i++){
                    pos = parameters.find(';');
                    articles.push_back(parameters.substr(0, pos));
                    parameters = parameters.substr(pos+1, taille-(pos+1));
                }
                break;
            case 3: editor = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
        int taille = parameters.size();
    }
}

int Magasine :: getNbArticles(){
    return nbArticles;
}

list<string> Magasine :: getArticles(){
    return articles;
}

string Magasine :: getEditor(){
    return editor;
}

void Magasine::show(){
    cout<<"...MAGAZINE..."<<getId()<<endl;
    Media::show();
    cout<<"Number of Articles : "<<nbArticles<<endl;
    cout << "--- Articles ---" << endl;
    for(string articles : articles){
        cout<<"Articles : "<<articles<<endl;
    }
    cout << "---------" << endl;
    cout<<"Editor : "<<editor<<endl;
}

string Magasine::toString(){
    string toString = "Magasine;";
    toString += Book::toString();
    toString += ";"+to_string(nbArticles)+";";
    for(string articles : articles){
        toString += articles+";";
    }
    toString += editor;
    return toString;
}