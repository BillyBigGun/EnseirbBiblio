#include "loadCommand.h"

void LoadCommand::execute(Mediatheque* mediatheque, string filename){
    if(filename.empty()){
        cout << "Please enter a filename with this command" << endl;
        return;
    }
    mediatheque->loadMediatheque(filename);
}