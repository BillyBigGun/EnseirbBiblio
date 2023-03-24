
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

public:
    Mediatheque();
    Mediatheque(string fileName);
    ~Mediatheque();

    void addMedia(Media media);
    void deleteMedia(Media media);
    map<int, Media> getMedias();

    Media findById(int id);

    /**
     * @brief Search media in the mediatheque that contain this title
     * 
     * @param title The title name for the search
     * @param currentSearch The current search
     * @return map<int, Media> The map containing all media that contain the title name
     */
    map<int, Media> findByTitle(string title, map<int, Media> currentSearch);
    /**
     * @brief Search media in the mediatheque that contain this author name
     * 
     * @param author The name of the author for the search
     * @param currentSearch The current search
     * @return map<int, Media> The map of all the media that contain this author name
     */
    map<int, Media> findByAuthor(string author, map<int, Media> currentSearch); 
    
    /**
     * @brief Search media in the mediatheque that contain this style
     * 
     * @param style The style for the search
     * @param currentSearch The current search
     * @return map<int, Media> The map of all the media that contain this style
     */
    map<int, Media> findByStyle(string style, map<int, Media> currentSearch);

   /**
    * @brief Search media in the mediatheque that contain this track
    * 
    * @param track The name of the track for the search
    * @param currentSearch The current search
    * @return map<int, Media> The map of all the media that contain that track
    */
    map<int, Media> findByTrack(string track, map<int, Media> currentSearch);

    /**
     * @brief Reset the search to be able to search from every media in the mediatheque. 
     * Reset by making it equal to the medaitheque list
     * 
     * @param currentSearch
     */
    void clearSearch(map<int, Media> currentSearch);

    /**
     * @brief Print the information about the media
     * 
     * @param id The id of the media to print
     */
    void showMedia(int id); 

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