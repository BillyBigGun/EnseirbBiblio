#include "book.h"
#include "CD.h"
#include "digitalRessources.h"
#include "DVD.h"
#include "magazine.h"
#include "VHS.h"
#include "user.h"
#include "mediatheque.h"

#include <iostream>
//include assert
#include <assert.h>

// create a test for adding a media to the mediatheque
void testAddMedia(){
    string tracks[2] = {"track1","track2"}; 
    // Create a media
    CD cd(1,2,tracks,"author");

    // Add the media to the mediatheque
    Mediatheque mediatheque;
    mediatheque.addMedia(cd);

    // Check if the media is in the mediatheque
    map<int, Media> medias = mediatheque.getMedias();
    assert(medias.size() == 1);
    assert(medias[1].getId() == 1);
    assert(medias[1].getAuthor() == "author");
    assert(medias[1].getTracks() == tracks);

}

// create a test for deleting a media from the mediatheque
void testDeleteMedia(){
    string tracks[2] = {"track1","track2"}; 
    // Create a media
    CD cd(1,2,tracks,"author");

    // Add the media to the mediatheque
    Mediatheque mediatheque;
    mediatheque.addMedia(cd);

    // Delete the media from the mediatheque
    mediatheque.deleteMedia(cd);

    // Check if the media is in the mediatheque
    map<int, Media> medias = mediatheque.getMedias();
    assert(medias.size() == 0);
}

// create a test for finding a media by id
void testFindById(){
    string tracks[2] = {"track1","track2"}; 
    // Create a media
    CD cd(1,2,tracks,"author");

    // Add the media to the mediatheque
    Mediatheque mediatheque;
    mediatheque.addMedia(cd);

    // Find the media by id
    Media media = mediatheque.findById(1);

    // Check if the media is in the mediatheque
    assert(media.getId() == 1);
    assert(media.getAuthor() == "author");
}
// create a test for finding a media by title
void testFindByTitle(){
    string tracks[2] = {"track1","track2"}; 
    // Create a media
    CD cd(1,2,tracks,"author");

    // Add the media to the mediatheque
    Mediatheque mediatheque;
    mediatheque.addMedia(cd);

    // Find the media by title
    map<int, Media> medias = mediatheque.findByTitle("track1");

    // Check if the media is in the mediatheque
    assert(medias.size() == 1);
    assert(medias[1].getId() == 1);
    assert(medias[1].getAuthor() == "author");
}
// create a test for finding a media by author

// create a test for finding a media by style
// create a test for finding a media by track
// create a test for clearing the search
// create a test for showing a media
