#include "book.h"

Book::Book() : Media()
{
    cout << "Number of pages : ";
    cin >> nbPages;
    cout << "Year : ";
    cin >> date;
    cout << "Collection : ";
    cin >> collection;
    cout << "Resume : ";
    cin >> resume;
    
}

Book::Book(int id, string title, string author, string style, int _nbPages, string _date, string _collection, string _resume) : Media(id, title, author, style)
{
        nbPages = _nbPages;
        date = _date;
        collection = _collection;
        resume = _resume;
}

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
    cout<<"...BOOK..."<<getId()<<endl;
    Media::show();
    cout<<"Number of pages : "<<nbPages<<endl;
    cout<<"Year : "<<date<<endl;
    cout<<"Collection : "<<collection<<endl;
    cout<<"Resume : "<<resume<<endl;
}