

#include "mediatheque.h"


/**
 * @brief Split a string by a delimiter and return a vector of string
 * 
 * @param inputString the string to split 
 * @param delim the delimiter
 * @param outputString the vector of string to fill 
 */
void splitString(const string &inputString, const char delim, vector<string> &outputString) {
    stringstream ss(inputString);
    string item;
    while (getline(ss, item, delim)) {
        outputString.push_back(item);
    }
}

Mediatheque::Mediatheque(){
    clearSearch();
}

Mediatheque::Mediatheque(string filename){
    loadMediatheque(filename);

}

Mediatheque::~Mediatheque() = default;


void Mediatheque::addMedia(Media* media){
    cout << "Adding media to the mediatheque" << endl;
    int id = media->getId();
    
    mediaList.insert(make_pair(id, media));

    clearSearch();
}

void Mediatheque::deleteMedia(Media* media){
    int id = media->getId();

    delete media;

    mediaList.erase(id);

    clearSearch();
}

void Mediatheque::reset(){
    for (auto media_ite : mediaList){
        delete media_ite.second;
    }
    mediaList.clear();
    currentSearch.clear();
}

map<int, Media*> Mediatheque::getMedias(){
    return mediaList;
}


Media* Mediatheque::findById(int id){
    
    map<int, Media*>::iterator media_ite = mediaList.find(id); 
    
    //If the media exist
    if(media_ite != mediaList.end()){
        return media_ite->second; // The value of the iterator
    }
    else{
        // The media is not found in the map
        throw runtime_error( "Media not found in map for searching by ID : " + id);
    }     

}
map<int, Media*> Mediatheque::findByTitle(string title){
    
    map<int, Media*> newSearch;
    // Compare the titles and add to a map is they match
    //for (auto i : mediaList)
    for (map<int, Media*>::iterator i = currentSearch.begin(); i != currentSearch.end(); ++i){
        // Second == media
        Media* currentMedia = i->second;
        string mediaTitle = currentMedia->getTitle();
        // Find if a substring in the title correspond to the title in parameter
        // Add it to the new search
        if(mediaTitle.find(title) != string::npos){
            newSearch.insert({currentMedia->getId(), currentMedia});
        }
    }

    return newSearch;
}
map<int, Media*> Mediatheque::findByAuthor(string author){

    map<int, Media*> newSearch;
    for (auto media_ite : currentSearch){
        // Second == media
        Media* currentMedia = media_ite.second;
        string mediaAuthor = currentMedia->getAuthor();
        // Find if a substring in the title correspond to the title in parameter
        // Add it to the new search
        if(mediaAuthor.find(author) != string::npos){
            newSearch.insert({currentMedia->getId(), currentMedia});
        }
    }

    return newSearch;
} 

map<int, Media*> Mediatheque::findByStyle(string style){

    map<int, Media*> newSearch;
    for (auto media_ite : currentSearch){
        // Second == media
        Media* currentMedia = media_ite.second;
        string mediaStyle = currentMedia->getStyle();
        // Find if a substring in the title correspond to the title in parameter
        // Add it to the new search
        if(mediaStyle.find(style) != string::npos){
            newSearch.insert({currentMedia->getId(), currentMedia});
        }
    }

    return newSearch;
}

map<int, Media*> Mediatheque::search(string chaine){

    map<int, Media*> newSearch;

    for(auto media_ite : currentSearch){
        // Second == media
        Media* currentMedia = media_ite.second;
        string mediaAuthor = currentMedia->getAuthor();
        string mediaStyle = currentMedia->getStyle();
        string mediaTitle = currentMedia->getTitle();
       
        // Find if a substring in the title, the author or the style correspond to the title in parameter
        if(mediaAuthor.find(chaine) != string::npos || mediaStyle.find(chaine) != string::npos || mediaTitle.find(chaine) != string::npos){
            newSearch.insert({currentMedia->getId(), currentMedia});
        }
    }

    currentSearch = newSearch;

    showSearch();
    return newSearch;
}

void Mediatheque::clearSearch(){
    currentSearch.clear();
    for(auto x : mediaList)
    {
        currentSearch.insert(x);
    }
    
}
void Mediatheque::showMedia(int id){
    try{
        Media* media = findById(id);
        media->show();
        // TODO Add the function to display the media in each media
    }
    catch(exception e){printf("Media Not found. Cannot print it's value.");}
    

} //Print the information about the media

void Mediatheque::showSearch(){
    for(auto x : currentSearch){
        x.second->show(); 
        cout << endl;
    }
}

void createMediaFromString(string mediaString){
    // substring with delimiter 
    // vector<string> mediaInfo;
    // splitString(mediaString, ';', mediaInfo);

    // // Depending on the type of media, create the right media
    // if (mediaInfo[0].compare("Book") == 0)
    // {
    //     Book* book = new Book(mediaInfo[1], mediaInfo[2], mediaInfo[3], mediaInfo[4], mediaInfo[5], mediaInfo[6]);
    //     Mediatheque::addMedia(book);
    // }
    // else if(mediaInfo[0].compare("CD")){
    //     CD* cd = new CD(mediaInfo[1], mediaInfo[2], mediaInfo[3], mediaInfo[4], mediaInfo[5], mediaInfo[6]);
    //     Mediatheque::addMedia(cd);
    // }
    // else if(mediaInfo[0].compare("DVD")){
    //     DVD* dvd = new DVD(mediaInfo[1], mediaInfo[2], mediaInfo[3], mediaInfo[4], mediaInfo[5], mediaInfo[6]);
    //     Mediatheque::addMedia(dvd);
    // }
    // else{
    //     throw new runtime_error("The media type is not recognized.");
    // }

}

void Mediatheque::loadMediatheque(string filename){
    // string filePath = Database_Path + filename;
    // int max_char = 1000;
    // char mediaChar[max_char];
    // char delimiter = '\n';

    // ifstream readFile(filePath);
    // if(readFile.good())
    // {
    //     //Check if end of file
    //     while(readFile.getline(mediaChar, max_char, delimiter) != istream().end()){
    //         string mediaString = mediaChar.toString();
    //         createMediaFromString(mediaString);
    //     }
        
    // }
    // else{
    //     throw new runtime_error("The file could not be open.");
    // }
    

} // Load the mediatheque from a filename

void Mediatheque::saveMediatheque(string filename){
    string filepath = Database_Path + filename;

    ofstream writeFile;
    writeFile.open(filepath);
    
    if(writeFile.good())
    {
        for (map<int, Media*>::iterator i = mediaList.begin(); i != mediaList.end(); ++i){
            Media* current_media = i->second;

            writeFile << current_media->toString() << endl;
        }

        writeFile.close();
    }
    else{
        throw new runtime_error("The file could not be open.");
    }

    
} // Save the mediatheque to a file text
