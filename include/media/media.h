#ifndef MEDIA_H
#define MEDIA_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Media{
    public : 
    Media(){}
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
    void borrow(int _userBorrowId);
    string getTitle();
    string getAuthor();
    int getId();
    bool available();
    bool reserved();
    void reserveMedia(int _userReserveId);
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
    int userReserveId;
    int userBorrowId;
    //methodes

};

#endif