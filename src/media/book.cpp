#include "book.h"
#include<iostream>
#include<fstream>
#include<string>


int  Book :: getNbPages(){
    return nbPages;
}

string Book ::  getDate(){
    return date;
}

string  Book :: getCollection(){
    return collection;
}

string Book ::  getResume(){
    return resume;
}

void Book::show(){
    cout<<"...BOOK..."<<id<<endl;
    Media::show();
    cout<<"Number of pages : "<<nbPages<<endl;
    cout<<"Year : "<<date<<endl;
    cout<<"Collection : "<<collection<<endl;
    cout<<"Resume : "<<resume<<endl;
}