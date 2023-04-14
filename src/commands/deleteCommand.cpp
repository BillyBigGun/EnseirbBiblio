
#include "deleteCommand.h"

void DeleteCommand::execute(Mediatheque mediatheque, string id){
    int id_int = 0;
    //Convert param in ID
    try{
        
        id_int = stoi(id);
        Media media = mediatheque.findById(id_int);
        mediatheque.deleteMedia(media);
    }
    catch(std::invalid_argument){
        cout << "The string in the command delete could not be parsed";
    }
}
