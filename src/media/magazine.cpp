#include "magazine.h"
#include<iostream>
#include<fstream>
#include<string>


int Magasine :: getNbArticles(){
    return nbArticles;
}

string Magasine :: getArticles(){
    return articles;
}

string Magasine :: getEditor(){
    return editor;
}

void Magasine::show(){
    cout<<"...MAGAZINE..."<<id<<endl;
    Media::show();
    cout<<"Number of Articles : "<<nbArticles<<endl;
    cout<<"Articles : "<<articles<<endl;
    cout<<"Editor : "<<editor<<endl;
}