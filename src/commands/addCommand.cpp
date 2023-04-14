
#include "addCommand.h"



void AddCommand::execute(Mediatheque* mediatheque, string type)
{
    string mediaType;
    cout << "What is the type of media that you want to add" << endl;
    //cin >> mediaType;
    //TODO creer le constructeur par defaut qui demande au user d<entree les infos

    if(mediaType.compare("BOOK") == 0){
        mediatheque->addMedia(*(new Book()));
    }
    else if(mediaType.compare("CD") == 0){
        mediatheque->addMedia(*(new CD()));
    }
    else if(mediaType.compare("DIGITAL_RESSOURCE") == 0){
        mediatheque->addMedia(*(new digitalRessources()));
    }
    else if(mediaType.compare("DVD") == 0){
        mediatheque->addMedia(*(new DVD()));
    }
    else if(mediaType.compare("MAGASINE") == 0){
        mediatheque->addMedia(*(new Magasine()));
    }
    else if(mediaType.compare("VHS") == 0){
        mediatheque->addMedia(*(new VHS()));
    }
    
}