#include "book.h"

Book::Book() : Media()
{
    string temp;
    cout << "Number of pages : ";
    getline(cin, temp);
    nbPages = stoi(temp);

    cout << "Year : ";
    getline(cin, date);

    cout << "Collection : ";
    getline(cin, collection);
    
    cout << "Resume : ";
    getline(cin, resume);
    
}

Book::Book(int id, string title, string author, string style, int _nbPages, string _date, string _collection, string _resume) : Media(id, title, author, style)
{
        nbPages = _nbPages;
        date = _date;
        collection = _collection;
        resume = _resume;
}

Book::Book(string* parameters):Media(parameters)
{
    int taille = parameters->size();
    int x=1;
    while(x<5 && taille!=0){
        int pos = parameters->find(';');
        switch(x)
        {
            case 1: 
                nbPages = stoi(parameters->substr(0, pos));
                break;
            case 2: 
                date = parameters->substr(0, pos);
                break;
            case 3: 
                collection = parameters->substr(0, pos);
                break;
            case 4: 
                resume = parameters->substr(0, pos);
                break;
        }
        x++;
        *parameters = parameters->substr(pos+1, taille-(pos+1));
        taille = parameters->size();
    } 
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
    string toString = "Book;";
    toString += Media::toString();
    return toString+";"+to_string(nbPages)+";"+date+";"+collection+";"+resume;
}