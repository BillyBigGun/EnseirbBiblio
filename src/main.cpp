
#include <iostream>
#include <string.h>

using namespace std;

#include "commandManager.h"
#include "book.h"
#include "CD.h"
#include "digitalRessources.h"
#include "DVD.h"
#include "magazine.h"
#include "VHS.h"
#include "user.h"
#include "mediatheque.h"

int main(int argc, char *argv[]){

    CommandManager commandManager;
    Book book = Book(1, "Le petit prince", "Antoine de Saint-Exupéry", "Sci-Fi", 200, "1999-10-12", "collection", "resume");

    book.show();
    return 0;
}