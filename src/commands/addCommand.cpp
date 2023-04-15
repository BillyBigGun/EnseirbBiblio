
#include "addCommand.h"



void AddCommand::execute(Mediatheque* mediatheque, string type)
{
    string mediaType = type;
    cout << "What is the type of media that you want to add" << endl;
    //cin >> mediaType;
    //TODO creer le constructeur par defaut qui demande au user d<entree les infos
    
    try{
        if(mediaType.compare("BOOK") == 0){
            cout << "Adding a book" << endl;
            mediatheque->addMedia((new Book()));
        }
        else if(mediaType.compare("CD") == 0){
            cout << "Adding a CD" << endl;
            mediatheque->addMedia((new CD()));
        }
        else if(mediaType.compare("DIGITAL_RESSOURCE") == 0){
            cout << "Adding a digital ressource" << endl;
            mediatheque->addMedia((new digitalRessources()));
        }
        else if(mediaType.compare("DVD") == 0){
            cout << "Adding a DVD" << endl;
            mediatheque->addMedia((new DVD()));
        }
        else if(mediaType.compare("MAGASINE") == 0){
            cout << "Adding a magasine" << endl;
            mediatheque->addMedia((new Magasine()));
        }
        else if(mediaType.compare("VHS") == 0){
            cout << "Adding a VHS" << endl;
            mediatheque->addMedia((new VHS()));
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