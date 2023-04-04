#ifndef MEDIA_H
#define MEDIA_H

#include<iostream>
#include<fstream>
#include<string>

#include "../user.h"

using namespace std;

class Media{
    public : 
    //constructeur
    Media(int _id, string _title, string _author, string _style){
        id = _id;
        title = _title;
        author = _author;
        style = _style;
        isAvailable = 1;
        reserve = 0;
        }
    //deconstructeur
    ~Media(){
    }

    //methodes
    void borrow(User _userBorrow);
    string getTitle();
    string getAuthor();
    int getId();
    bool available();
    bool reserved();
    void reserveMedia(User _userReserve);
    void returnMedia();
    void show();

    private : 
    //attributs
    int id;
    string title;
    string author;
    string style;
    bool isAvailable;
    bool reserve;
    User userReserve;
    User userBorrow;
    //methodes

};

#endif