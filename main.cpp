#include "graphics.hpp"
#include "Widget.hh"
#include "EventHandler.hh"
#include "Game.hh"

using namespace genv;

int main() {
    event evt;
    Game play;
    EventHandler input;

    gout.load_font("LiberationSerif-BoldItalic", 60, true);
    gout.open(930, 620);

        play.field();
        play.menu();
        play.reFresh();

    while (gin >> evt) {

        play.clearScreen();

        play.field();
        play.menu();

        input.escape(evt);
        input.gamer();
        input.buttons(evt);
        input.action(evt);
        input.placedPieces();
        input.gameOver();

        if (input.getExit() > 0){
            break;
        }

        play.reFresh();
    }

    return 0;
}

