#include <iostream>
#include <string>

#include "Hub.h"


int main(){

    ConsoleHub hub;
    hub.affMsg();
    hub.tryLoadConfig("config.ezh");
    hub.listenInputs();

    return 0;
}
