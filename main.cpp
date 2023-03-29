
#include <iostream>
#include <fstream>
#include <string>

#include "commandManager.h"

int main(int argc, char *argv[])
{
    CommandManager* commandManager = new CommandManager();

    commandManager->executeCommand("ADD CD");

    return 0;
}