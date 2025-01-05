#include <iostream>
#include "game.h"
#include "view.h"
#include <algorithm>
#include <fstream>
#include "controller.h"

using namespace std;

int main(){
    Game myGame = Game();
    View myView = View(myGame);

    Controller controller = Controller(myGame,myView);
    controller.play();


}
