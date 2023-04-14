#include "resetCommand.h"
void ResetCommand::execute(Mediatheque* mediatheque, string type){
    string answer;
    cout << "Are you sure you want to reset? (yes/no=default)" << endl;
    cin >> answer;

    if (answer.compare("yes") == 0){
        
        //mediatheque.reset();
    }
    else{
        cout << "Reset canceled" << endl;
    }

}