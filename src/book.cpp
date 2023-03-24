#include "CD.h"
#include<iostream>
#include<fstream>
#include<string>


int  book :: getNbPages(){
    return nbPages;
}

string book ::  getDate(){
    return date;
}

string  book :: getCollection(){
    return collection;
}

string book ::  getResume(){
    return resume;
}