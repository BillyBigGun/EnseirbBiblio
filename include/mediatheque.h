
#ifndef MEDIATHEQUE_H
#define mEDIATHEQUE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "media.h"

using namespace std;

class Mediatheque{

private:
    
    map<int, Media> mediaList; // The list of all media in the mediatheque
    map<int, Media> mediaSearch; // The list of media in the current search

public:
    Mediatheque();
    Mediatheque(string fileName);
    ~Mediatheque();

    void addMedia(Media media);
    void deleteMedia(Media media);
    map<int, Media> getMedias();

    Media findById(int id);
    map<int, Media> findByTitle(string title);
    map<int, Media> findByAuthor(string author); 
    map<int, Media> findByStyle(string style);
    map<int, Media> findByAuthor(string author);
    map<int, Media> findByTrack(string track);

    void clearSearch();
    void showMedia(int id); //Print the information about the media

    loadMediatheque(string filename); // Load the mediatheque from a filename
    saveMediatheque(string filename); // Save the mediatheque to a file text

    void reset(); // Clear the mediatheque
};



#endif