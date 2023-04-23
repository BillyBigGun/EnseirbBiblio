#include "searchCommand.h"

void SearchCommand::execute(Mediatheque* mediatheque, string param){
    map<int, Media*> search = mediatheque->search(param);
}