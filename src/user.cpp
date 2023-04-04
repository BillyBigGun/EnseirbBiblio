#include "../include/user.h"
#include<iostream>
#include<fstream>
#include<string>


int User::getId(){
	return id;
}

string User::getName(){
	return name;
}

string User :: getSurname(){
	return surname;
}