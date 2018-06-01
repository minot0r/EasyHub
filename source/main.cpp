<<<<<<< HEAD
=======
#include <iostream>
#include <string>

>>>>>>> eb3df076fdaf8d501bff1d2d125d89a0f12f085c
#include "../includes/Hub.h"


int main(){

    ConsoleHub hub;
    hub.affMsg();
    hub.tryLoadConfig("config.ezh");
    hub.listenInputs();

    return 0;
}
