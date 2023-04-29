
#include "addCommand.h"



void AddCommand::execute(Mediatheque* mediatheque, string type)
{
    string mediaType = type;
    cout << "What is the type of media that you want to add" << endl;
    
    try{
        if(mediaType.compare("BOOK") == 0){
            cout << "Adding a book" << endl;
            Book* book = new Book();
            mediatheque->addMedia(book);
        }
        else if(mediaType.compare("CD") == 0){
            cout << "Adding a CD" << endl;
            CD* cd = new CD();
            mediatheque->addMedia(cd);
        }
        else if(mediaType.compare("DIGITAL_RESSOURCE") == 0){
            cout << "Adding a digital ressource" << endl;
            DigitalRessources* digitalRessources = new DigitalRessources();
            mediatheque->addMedia(digitalRessources);
        }
        else if(mediaType.compare("DVD") == 0){
            cout << "Adding a DVD" << endl;
            DVD* dvd = new DVD();
            mediatheque->addMedia(dvd);
        }
        else if(mediaType.compare("MAGASINE") == 0){
            cout << "Adding a magasine" << endl;
            Magasine* magasine = new Magasine();
            mediatheque->addMedia(magasine);
        }
        else if(mediaType.compare("VHS") == 0){
            cout << "Adding a VHS" << endl;
            VHS* vhs = new VHS();
            mediatheque->addMedia(vhs);
        }
        else{
            cout << "ERROR : media type not found" << endl;
            cout << "The media type should be in all CAPS" << endl;
        }
    }
    catch(const char* msg){
        cerr << msg << endl;
        cout << "You probably didn't enter a valid parameter. Please retry with correct data" << endl;
    }
    
    
}