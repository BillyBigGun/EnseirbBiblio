

#include "mediatheque.h"

Mediatheque::Mediatheque(){

}

Mediatheque::Mediatheque(string filename){

}

Mediatheque::~Mediatheque() = default;


void Mediatheque::addMedia(Media media){
    int id = media.getId();

    mediaList.insert(make_pair(id, media));
}

void Mediatheque::deleteMedia(Media media){
    int id = media.getId();

    mediaList.erase(id);
}

map<int, Media> Mediatheque::getMedias(){
    return mediaList;
}


Media Mediatheque::findById(int id){
    
    map<int, Media>::iterator media_ite = mediaList.find(id); 
    
    //If the media exist
    if(media_ite != mediaList.end()){
        return media_ite->second; // The value of the iterator
    }
    else{
        // The media is not found in the map
        throw runtime_error( "Media not found in map for searching by ID : " + id);
    }     

}
map<int, Media> Mediatheque::findByTitle(string title, map<int, Media> currentSearch){
    
    map<int, Media> newSearch;
    // Compare the titles and add to a map is they match
    //for (auto i : mediaList)
    for (map<int, Media>::iterator i = currentSearch.begin(); i != currentSearch.end(); ++i){
        // Second == media
        Media currentMedia = i->second;
        string mediaTitle = currentMedia.getTitle();
        // Find if a substring in the title correspond to the title in parameter
        // Add it to the new search
        if(mediaTitle.find(title) != string::npos){
            newSearch.insert({currentMedia.getId(), currentMedia});
        }
    }

    return newSearch;
}
map<int, Media> Mediatheque::findByAuthor(string author, map<int, Media> currentSearch){

    map<int, Media> newSearch;
    for (auto media_ite : currentSearch){
        // Second == media
        Media currentMedia = media_ite.second;
        string mediaAuthor = currentMedia.getAuthor();
        // Find if a substring in the title correspond to the title in parameter
        // Add it to the new search
        if(mediaAuthor.find(author) != string::npos){
            newSearch.insert({currentMedia.getId(), currentMedia});
        }
    }

    return newSearch;
} 

// TODO Get only the media that have a style
map<int, Media> Mediatheque::findByStyle(string style, map<int, Media> currentSearch){

    // map<int, Media> newSearch;
    // for (auto media_ite : currentSearch){
    //     // Second == media
    //     Media currentMedia = media_ite.second;
    //     string mediaStyle = currentMedia.getStyle();
    //     // Find if a substring in the title correspond to the title in parameter
    //     // Add it to the new search
    //     if(mediaTitle.find(style) != string::npos){
    //         newSearch.insert({currentMedia.getId(), currentMedia});
    //     }
    // }

    // return newSearch;
}

map<int, Media> Mediatheque::findByTrack(string track, map<int, Media> currentSearch){

}

void Mediatheque::clearSearch(map<int, Media> currentSearch){
    currentSearch = mediaList;
}
void Mediatheque::showMedia(int id){

} //Print the information about the media

void loadMediatheque(string filename){

} // Load the mediatheque from a filename

void saveMediatheque(string filename){

} // Save the mediatheque to a file text
