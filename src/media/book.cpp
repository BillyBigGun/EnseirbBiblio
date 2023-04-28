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

Book::Book(string parameters)
{
    parameters = Media::Media(parameters);
    while(x<5 or taille!=0){
        int pos = parameters.find(';');
        switch(x)
        {
            case 1: nbPages = parameters.substr(0, pos);
            case 2: date = parameters.substr(0, pos);
            case 3: collection = parameters.substr(0, pos);
            case 4: resume = parameters.substr(0, pos);
        }
        x++;
        parameters = parameters.substr(pos+1, taille-(pos+1));
    }
    return parameters;
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

string Book::toString(){
    string toString = 'book;';
    toString += Media::toString();
    return toString+";"+to_string(nbPages)+";"+date+";"+collection+";"+resume;
}