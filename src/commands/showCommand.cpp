#include "showCommand.h"

void ShowCommand::execute(Mediatheque* mediatheque, string id){
    int id_int = 0;
    //Convert param in ID
    try{
        
        id_int = stoi(id);
        mediatheque->showMedia(id_int);
    }
    catch(std::invalid_argument){
        cout << "The string in the command show could not be parsed";
    }
}

