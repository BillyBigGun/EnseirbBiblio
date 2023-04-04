

#include "mediatheque.h"

Mediatheque::Mediatheque(){
    clearSearch();
}

Mediatheque::Mediatheque(string filename){
    loadMediatheque(filename);

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
map<int, Media> Mediatheque::findByTitle(string title){
    
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
map<int, Media> Mediatheque::findByAuthor(string author){

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
map<int, Media> Mediatheque::findByStyle(string style){

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

map<int, Media> Mediatheque::findByTrack(string track){

}

void Mediatheque::clearSearch(){
    currentSearch = mediaList;
}
void Mediatheque::showMedia(int id){
    try{
        Media media = findById(id);
        media.show();
        // TODO Add the function to display the media in each media
    }
    catch(exception e){printf("Media Not found. Cannot print it's value.");}
    

} //Print the information about the media

void Mediatheque::showSearch(){
    for(auto x : currentSearch){
        x.second.show(); 
    }
}

void createMediaFromString(string mediaString){

}

void Mediatheque::loadMediatheque(string filename){
    string filePath = Database_Path + filename;
    int max_char = 1000;
    char mediaChar[max_char];
    char delimiter = '\n';

    ifstream readFile(filePath);
    if(readFile.good())
    {
        while(readFile.getline(mediaChar, max_char, delimiter) != istream().end()){
            string mediaString = mediaChar.toString();
            createMediaFromString(mediaString);
        }
        
    }

} // Load the mediatheque from a filename

void Mediatheque::saveMediatheque(string filename){
    string filepath = Database_Path + filename;

    ofstream writeFile;
    writeFile.open(filepath);
    
    if(writeFile.good())
    {
        for (map<int, Media>::iterator i = mediaList.begin(); i != mediaList.end(); ++i){
            Media current_media = i->second;
            
            // TODO fonction toString()
            // TODO fonction fromString()
            //writeFile << current_media.toString() << endl;
        }

        writeFile.close();
    }
    else{
        throw new runtime_error("The file could not be open.");
    }

    
} // Save the mediatheque to a file text
