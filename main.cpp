
#include <iostream>
#include <fstream>
#include <string>

#include "media.h"
#include "book.h"
#include "CD.h"
#include "digitalRessources.h"
#include "DVD.h"
#include "magazine.h"
#include "VHS.h"

#include "user.h"

int main(int argc, char *argv[])
{
    // CommandManager* commandManager = new CommandManager();

    // commandManager->executeCommand("ADD CD");

    // return 0;

    // User User1(0001, "Jean","LaFrite");
    // cout << User1.getName() << endl;

    Book Book1(001, "le livre de la jungle", "Moi","Disney", 1674, 2000, "Mowgli", "c'est l'histoire de Mowgli");
    Book1.show();

}