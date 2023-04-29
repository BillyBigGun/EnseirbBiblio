#include "media.h"


Media::Media(){
    string temp;
    cout << "ID : ";
    getline(cin, temp);
    id = stoi(temp);

    cout << "Title : ";
    getline(cin, title);

    cout << "Author : ";
    getline(cin, author);

    cout << "Style : ";
    getline(cin, style);
    
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

Media::Media(string* parameters)
{
    int taille = parameters->size();
    int x=1;
    while(x<5 && taille!=0){
        int pos = parameters->find(';');
        
        switch(x)
        {
            case 1: 
                id = stoi(parameters->substr(0, pos));
                break;
            case 2: 
                title = parameters->substr(0, pos);
                break;
            case 3: 
                author = parameters->substr(0, pos);
                break;
            case 4: 
                style = parameters->substr(0, pos);
                break;
        }
        x++;
        *parameters = parameters->substr(pos+1, taille-(pos+1));
        taille = parameters->size();
    }
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

string Media :: getStyle(){
    return style;
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
    cout<<"Style : "<<style<<endl;
}

string Media::toString(){
    return to_string(getId())+";"+title+";"+author+";"+style;
}