
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

void test_add_command(CommandManager* commandManager){
    
    string tracks[] = {"TRACK1", "TRACK2"};
    
    Media * book = new Book(1, "Le petit prince", "Antoine de Saint-Exupéry", "Sci-Fi", 200, "1999", "collection", "resume");
    commandManager->addMedia(book);
    
    Media * cd = new CD(2, "Boom", "Will", "style", "2000", 20, 2, tracks, "company");
    commandManager->addMedia(cd);
    
    Media * dvd = new DVD(3, "Batman", "Smith", "style", 20, 2, tracks);
    commandManager->addMedia(dvd);
    
    Media * vhs = new VHS(4, "Wolf", "Gab", "style", 20, "production");
    commandManager->addMedia(vhs);
    
    Media * digitalRessource = new DigitalRessources(5, "Bugsbunny", "Gregs", "style", 20, "url", "type");
    commandManager->addMedia(digitalRessource);
    
    Media * magasine = new Magasine(6, "Docteur", "Elen", "style", 20, "2000", "collection", "resume", 2, tracks, "editor");
    commandManager->addMedia(magasine);

    commandManager->executeCommand("LIST");
}

void test_add_delete_commands(CommandManager* commandManager){
    Media * book = new Book(1, "Le petit prince", "Antoine de Saint-Exupéry", "Sci-Fi", 200, "1999", "collection", "resume");
    commandManager->addMedia(book);
    commandManager->executeCommand("LIST");
    commandManager->executeCommand("DELETE 1");
    commandManager->executeCommand("LIST");
}

void test_search_command(CommandManager* commandManager){

    test_add_command(commandManager);

    commandManager->executeCommand("SEARCH B");
    commandManager->executeCommand("SEARCH o");
}

void test_bye_command(CommandManager* commandManager){
    while(1)
        commandManager->executeCommand("BYE");
}

void test_save_command(CommandManager* commandManager){
    test_add_command(commandManager);
    commandManager->executeCommand("SAVE file.txt");
}

void test_load_command(CommandManager* commandManager){
    commandManager->executeCommand("LOAD file.txt");
    commandManager->executeCommand("LIST");
}

void run();

int main(int argc, char *argv[]){

    CommandManager commandManager;
    
    // test_add_command(&commandManager);
    // test_add_delete_commands(&commandManager);
    // test_search_command(&commandManager);
    // test_bye_command(&commandManager);
    // test_save_command(&commandManager);
    // test_load_command(&commandManager);

    //test_load_command(&commandManager);
    run();
    
    return 0;
}

void run(){
    CommandManager commandManager;
    string command;
    cout << "Welcome to the mediatheque" << endl;
    while(1){
        cout << endl << "Please enter a command" << endl;
        cout << "Type HELP to get a list of commands" << endl << "> " ;
        getline(cin, command);
        commandManager.executeCommand(command);
    }
}