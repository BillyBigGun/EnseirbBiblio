#include "saveCommand.h"

void SaveCommand::execute(Mediatheque mediatheque, string filename){
    mediatheque.saveMediatheque(filename);
}