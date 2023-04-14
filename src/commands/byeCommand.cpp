
#include "byeCommand.h"

void ByeCommand::execute(Mediatheque mediatheque, string type)
{
    //mediatheque.reset();

    cout << "Bye Bye " << endl; 
    
    throw runtime_error("BYE command");
}