#include "media.h"
#include<iostream>
#include<fstream>
#include<string>

from datetime import date, timedelta

void Media :: borrow(User _userBorrow){
    if(available=1){
        returnDate = date.today() + timedelta(weeks=3); //3 weeks delay
    userBorrow = _userBorrow;
    available = 0;
    }
    else 
        print("ERREUR media déjà emprunté");
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
    return available;
}


bool Media :: reserved(){
    return reserve;
}

string Media :: getReturnDate(){
    return returnDate;
}

void Media :: reserveMedia(User _userReserve){
    if(reserved()==1){
        print("ERREUR media déjà réservé");
    }
    else {
        userReserve = _userReserve;
        reserve=0;
    }
}

void Media :: returnMedia(){
    if(reserved()= 1){
        borrow(userReserve);
        reserve=0;
    }
    else {
        available=1;
    }
}