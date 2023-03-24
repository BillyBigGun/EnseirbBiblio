#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class Media{
    public : 
    //constructeur
    Media(){

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
    string getReturnDate();
    void reserveMedia(User _userReserve);
    void returnMedia();

    private : 
    //attributs
    int id;
    string title;
    string author;
    string style;
    bool available;
    bool reserve;
    User userReserve;
    User userBorrow;
    string returnDate;
    //methodes

};