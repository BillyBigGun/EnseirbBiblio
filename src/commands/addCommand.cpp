
#include "addCommand.h"



void AddCommand::execute(Mediatheque mediatheque, string type)
{
    string mediaType;
    cout << "What is the type of media that you want to add" << endl;
    cin >> mediaType;

    if(mediaType.compare("BOOK") == 0){
        mediatheque.addMedia(*(new book()));
    }
    else if(mediaType.compare("CD") == 0){
        mediatheque.addMedia(*(new CD()));
    }
    else if(mediaType.compare("DIGITAL_RESSOURCE") == 0){
        mediatheque.addMedia(*(new digitalRessources()));
    }
    else if(mediaType.compare("DVD") == 0){
        mediatheque.addMedia(*(new DVD()));
    }
    else if(mediaType.compare("MAGASINE") == 0){
        mediatheque.addMedia(*(new magasine()));
    }
    else if(mediaType.compare("VHS") == 0){
        mediatheque.addMedia(*(new VHS()));
    }
    
}