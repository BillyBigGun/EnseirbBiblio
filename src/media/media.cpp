#include "../../include/media/media.h"
#include<iostream>
#include<fstream>
#include<string>
#include<chrono>

void Media :: borrow(int _userBorrowId){
    if(isAvailable==1){
    userBorrowId = _userBorrowId;
    isAvailable = 0;
    }
    else 
        cout<<"ERROR media already borrowed"<<endl;
}

string Media :: getTitle(){
    return title;
}


string Media :: getAuthor(){
    return author;
}

int Media :: getId(){
    return id;
}


bool Media :: available(){
    return isAvailable;
}


bool Media :: reserved(){
    return reserve;
}

void Media :: reserveMedia(int _userReserveId){
    if(reserved()==1){
        cout<<"ERROR media already reserved"<<endl;
    }
    else {
        userReserveId = _userReserveId;
        reserve=0;
    }
}

void Media :: returnMedia(){
    if(reserved()== 1){
        borrow(userReserveId);
        reserve=0;
    }
    else {
        isAvailable=1;
    }
}

void Media :: show(){
    cout<<"ID : "<<id<<endl;
    cout<<"Title : "<<title<<endl;
    cout<<"Author : "<<author<<endl;
}