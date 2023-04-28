#include "magazine.h"
#include<iostream>
#include<fstream>
#include<string>

Magasine::Magasine() : Media(){
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

Magasine::Magasine(string parameters)
{
    parameters = Book::Book(parameters);
    while(x<4 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: nbArticles = parameters.substr(0, pos);
            case 2: article = parameters.substr(0, pos);
            case 3: editor = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
    }
    return parameters;
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
    string toString = 'Magasine;';
    toString += Book.toString()
    return toString+";"+nbArticles+";"+articles+";"+editor;
}