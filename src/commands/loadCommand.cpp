#include "loadCommand.h"

void LoadCommand::execute(Mediatheque* mediatheque, string filename){
    mediatheque->loadMediatheque(filename);
}