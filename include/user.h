#ifndef USER_H
#define USER_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class User {
    public : 
    //constructeur
    User(int _id, string _name, string _surname){
        id = _id;
        name = _name;
        surname = _surname;
    }

	//deconstructeur
    ~User(){}

	//attributs

    //methodes
    int getId();
    string getName();
    string getSurname();

	private : 
    //attributs
    int id;
    string name;
    string surname;
    //methodes
};

#endif