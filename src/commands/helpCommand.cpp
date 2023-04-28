
#include "helpCommand.h"

void HelpCommand::execute(Mediatheque* mediatheque, string param){
    cout << "List of commands:" << endl;
    cout << "ADD <media> : add a media to the mediatheque" << endl;
    cout << "BYE : exit the program" << endl;
    cout << "CLEAR : clear the current search in the mediatheque" << endl;
    cout << "DELETE <id> : delete a media from the mediatheque" << endl;
    cout << "HELP : display this help" << endl;
    cout << "LIST : list all the media in the mediatheque" << endl;
    cout << "LOAD : load a mediatheque from a file" << endl;
    cout << "RESET : reset the mediatheque" << endl;
    cout << "SAVE : save the mediatheque to a file" << endl;
    cout << "SEARCH <keyword> : search for medias in the mediatheque containing this keyword" << endl;
    cout << "SHOW <id> : show the details of a media" << endl;
    cout << endl;

}