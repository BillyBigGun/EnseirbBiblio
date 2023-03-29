#include "magazine.h"
#include<iostream>
#include<fstream>
#include<string>


int magasine :: getNbArticles(){
    return nbArticles;
}

string magasine :: getArticles(){
    return articles;
}

string magasine :: getEditor(){
    return editor;
}