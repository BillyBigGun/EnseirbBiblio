

#include "mediatheque.h"

Mediatheque::Mediatheque(){

}

Mediatheque::Mediatheque(string filename){

}

Mediatheque::~Mediatheque(){

}


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
    return mediaList.find(id);
}
map<int, Media> Mediatheque::findByTitle(string title){

}
map<int, Media> Mediatheque::findByAuthor(string author){

} 
map<int, Media> Mediatheque::findByStyle(string style){

}
map<int, Media> Mediatheque::findByAuthor(string author){

}
map<int, Media> Mediatheque::findByTrack(string track){

}

void Mediatheque::clearSearch(){

}
void Mediatheque::showMedia(int id){

} //Print the information about the media

void loadMediatheque(string filename){

} // Load the mediatheque from a filename
void saveMediatheque(string filename){

} // Save the mediatheque to a file text
