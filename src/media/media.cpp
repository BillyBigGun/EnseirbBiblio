#include "media.h"


Media::Media(){
    cout << "ID : ";
    cin >> id;
    cout << "Title : ";
    cin >> title;
    cout << "Author : ";
    cin >> author;
    cout << "Style : ";
    cin >> style;
    isAvailable = 1;
    reserve = 0;
}

 Media::Media(int _id, string _title, string _author, string _style){
        id = _id;
        title = _title;
        author = _author;
        style = _style;
        isAvailable = 1;
        reserve = 0;
}

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