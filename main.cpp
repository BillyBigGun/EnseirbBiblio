
#include <iostream>
#include <fstream>
#include <string>


#include "src/user.cpp"

int main(int argc, char *argv[])
{
    // CommandManager* commandManager = new CommandManager();

    // commandManager->executeCommand("ADD CD");

    // return 0;

    User User1(0001, "Jean","LaFrite");
    cout << User1.getName() << endl;


}