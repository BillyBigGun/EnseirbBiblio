
#include "commandManager.h"

CommandManager::CommandManager(){
    commands["ADD"] = new AddCommand();
    commands["BYE"] = new ByeCommand();
    commands["CLEAR"] = new ClearCommand();
    commands["DELETE"] = new DeleteCommand();
    commands["LIST"] = new ListCommand();
    commands["LOAD"] = new LoadCommand();
    commands["RESET"] = new ResetCommand();
    commands["SAVE"] = new SaveCommand();
    commands["SEARCH"] = new SearchCommand();
    commands["SHOW"] = new ShowCommand();
}

/**
 * @brief Split the command received in two if possible. 
 * Ex: "ADD book" --> ["ADD", "book"]. 
 * 
 * Check every caracters of the string until a space or the end of the string
 * The caracters before the space is the command type
 * If there a space, there is another param
 * If no space there is only the command type
 * 
 * @param command 
 * @return string* A array pf 2 elements. First element : Command. Second Element: Parameter (can be NULL).
 */
string* splitCommand(string command)
{
    string *split_command = new string[2]; //The return string

    string command_type;
    string command_param = NULL;

    int pos = 0;
    bool is_first_param = true;

    
    while(pos != command.length() - 1){
        if(is_first_param)
        {
            if(command[pos] = ' ')
                is_first_param = false;
            else
                command_type = command_type + command[pos];
        }
        else{
            command_param =command_param + command[pos];
        }
        pos++;
    }

    split_command[0] = command_type;
    split_command[1] = command_param;

    cout << split_command[0] << "|" << split_command[1];
    return split_command;
}

void CommandManager::executeCommand(string command){
    //Split the command if needed
    string* split_command = splitCommand(command);
    
    commands[split_command[0]]->execute(mediatheque, split_command[1]);

    delete split_command;
}