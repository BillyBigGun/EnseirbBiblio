

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
    clearSearch();
}

Mediatheque::~Mediatheque() = default;


void Mediatheque::addMedia(Media* media){
    cout << "Adding media to the mediatheque" << endl;
    int id = media->getId();
    
    //If the id is not already in the map
    if(mediaList.find(id) == mediaList.end()){
        mediaList.insert(make_pair(id, media));
    }
    else{
        cout << "This id is already in the mediatheque. Choose a different id" << endl;
        delete media;
    }

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
        cout << "Media not found in map for searching by ID : " <<  id << endl;
    }     
    return nullptr;
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
    }
    catch(exception e){printf("Media Not found. Cannot print it's value.");}
    

} //Print the information about the media

void Mediatheque::showSearch(){
    try{
        for(auto x : currentSearch)
        {
            x.second->show();
            cout << endl;
        }
    }
    catch(exception e)
    {printf("Media Not found. Cannot print it's value.");}
}

void Mediatheque::createMediaFromString(string line){
    int pos = line.find(';');
    int taille = line.size();
    string mediaType = line.substr(0, pos);

    line = line.substr(pos+1, taille);

    // Depending on the type of media, create the right media
    if (mediaType.compare("Book") == 0)
    {
        Book* book = new Book(&line);
        addMedia(book);
    }
    else if(mediaType.compare("CD") == 0){
        CD* cd = new CD(&line);
        addMedia(cd);
    }
    else if (mediaType.compare("DigitalRessources") == 0){
        DigitalRessources* digital = new DigitalRessources(&line);
        addMedia(digital);
    }
    else if(mediaType.compare("DVD") == 0){
        DVD* dvd = new DVD(&line);
        addMedia(dvd);
    }
    else if(mediaType.compare("Magasine") == 0){
        Magasine* magasine = new Magasine(&line);
        addMedia(magasine);
    }
    else if(mediaType.compare("VHS") == 0){
        VHS* vhs = new VHS(&line);
        addMedia(vhs);
    }
    else{
        cout << "The media type in the file is not recognized." << endl;
    }

}

void Mediatheque::loadMediatheque(string filename){
    if(filename.empty()){
        cout << "The filename is empty. Could not load the file" << endl;
        return;
    }

    string filePath = Database_Path + filename;
    string line;
    //char delimiter = '\n';

    ifstream readFile;
    readFile.open(filePath);

    if(readFile.good())
    {
        //Check if end of file
        while(!readFile.eof()){
            getline(readFile, line);
            createMediaFromString(line);
        }
        
    }
    else{
        cout << "The file could not be open." << endl;
    }
    

}

void Mediatheque::saveMediatheque(string filename){
    if(filename.empty()){
        cout << "The filename is empty. Could not save the file" << endl;
        return;
    }
    string filepath = Database_Path + filename;
    ofstream writeFile;
    writeFile.open(filepath);
    
    if(writeFile.good())
    {
        for (map<int, Media*>::iterator i = mediaList.begin(); i != mediaList.end(); ++i){
            Media* current_media = i->second;
            string mediaString = current_media->toString();
            writeFile << mediaString << endl;
        }

        writeFile.close();
    }
    else{
        //throw new runtime_error("The file could not be open.");
        cout << "The file could not be open." << endl;
    }

    
} // Save the mediatheque to a file text
