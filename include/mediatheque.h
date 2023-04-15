
#ifndef MEDIATHEQUE_H
#define MEDIATHEQUE_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream> 

#include "media.h"
#include "book.h"
#include "CD.h"
#include "digitalRessources.h"
#include "DVD.h"
#include "magazine.h"
#include "VHS.h"

// #include "user.h"


#define Database_Path "DatabaseTxt/"

using namespace std;

class Mediatheque{

private:
    
    map<int, Media*> mediaList; // The list of all media in the mediatheque
    map<int, Media*> currentSearch;
    // map<int, User> userList;
    // User currentUser;

public:
    Mediatheque();
    Mediatheque(string fileName);
    ~Mediatheque();

    // User getUser(int id);
    // map<int, User> getUsers();

    void addMedia(Media* media);

    void deleteMedia(Media* media);
    map<int, Media*> getMedias();

    Media* findById(int id);

    /**
     * @brief Search media in the mediatheque that contain this title
     * 
     * @param title The title name for the search
     * @param currentSearch The current search
     * @return map<int, Media> The map containing all media that contain the title name
     */
    map<int, Media*> findByTitle(string title);
    /**
     * @brief Search media in the mediatheque that contain this author name
     * 
     * @param author The name of the author for the search
     * @param currentSearch The current search
     * @return map<int, Media> The map of all the media that contain this author name
     */
    map<int, Media*> findByAuthor(string author); 
    
    /**
     * @brief Search media in the mediatheque that contain this style
     * 
     * @param style The style for the search
     * @param currentSearch The current search
     * @return map<int, Media> The map of all the media that contain this style
     */
    map<int, Media*> findByStyle(string style);

   /**
    * @brief Search media in the mediatheque that contain this track
    * 
    * @param track The name of the track for the search
    * @param currentSearch The current search
    * @return map<int, Media> The map of all the media that contain that track
    */
    map<int, Media*> findByTrack(string track);

    /**
     * @brief Reset the search to be able to search from every media in the mediatheque. 
     * Reset by making it equal to the medaitheque list
     * 
     * @param currentSearch
     */
    void clearSearch();

    /**
     * @brief Print the information about the media
     * 
     * @param id The id of the media to print
     */
    void showMedia(int id); 

    /**
     * @brief Display all the media in the search list
     * 
     */
    void showSearch();

    /**
     * @brief Load the mediatheque from a filename
     * 
     * @param filename the name of the file where the data is stored 
     */
    void loadMediatheque(string filename); 

    /**
     * @brief Save the current data of the mediatheque into a file
     * 
     * @param filename the name of the file where the data of the mediatheque will be stored
     */
    void saveMediatheque(string filename); 

    /**
     * @brief Delete all the data in the mediatheque
     * 
     */
    void reset(); // Clear the mediatheque
};



#endif