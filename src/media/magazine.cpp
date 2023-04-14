#include "magazine.h"
#include<iostream>
#include<fstream>
#include<string>


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