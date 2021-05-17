#include "Widget.hh"
#include "Game.hh"
#include "graphics.hpp"
#include "EventHandler.hh"

EventHandler::EventHandler()
{
    //ctor
}

EventHandler::~EventHandler()
{
    //dtor
}

void EventHandler :: escape(event evt){            // ESC GOMBBAL VALO KILEPES

    if (evt.type == ev_key && evt.keycode == key_escape) {

            exitel();
    }
}

void EventHandler :: buttons(event evt){            // MENU GOMBJAINAK KEZELESE

    if (evt.type == ev_mouse){

        // RESTART //
        if(evt.pos_x > 780 - gout.twidth(getB_1())/2 + 5 && evt.pos_x < 780 + gout.twidth(getB_1())/2 + 5 &&
           evt.pos_y > 110 - gout.cascent() - 5 && evt.pos_y < 110 + 5){
                   if (evt.button == 1){
                        button(getB_1(), 1);
                    }
                   if (evt.button == -1){
                        restart();
                    }

        // EXIT //
        } else if (evt.pos_x > 780 - gout.twidth(getB_2())/2 + 5 && evt.pos_x < 780 + gout.twidth(getB_2())/2 + 5 &&
           evt.pos_y > 210 - gout.cascent() - 5 && evt.pos_y < 210 + 5){
                   if (evt.button == 1){
                        button(getB_2(), 2);
                    }
                   if (evt.button == -1){
                        exitel();
                    }
        }
    }
}

void EventHandler :: gamer(){            // ERZEKELI ES KIJELZI KI EPPEN AZ AKTIV JATEKOS

    if(getValue() % 2 == 1){

        active_1();

    } else if(getValue() % 2 == 0){

        active_2();
    }
}

void EventHandler :: action(event evt){            // KOR ÉS X LERAKASA, JOKOR, JO HELYRE

    if (evt.type == ev_mouse && evt.button == 1){

        for(int i(0); i<20; i++){
            for(int j(0); j<20; j++){

                if (evt.pos_x > koord[i][j].x - 15 && evt.pos_x < koord[i][j].x + 13
                    && evt.pos_y > koord[i][j].y - 15 && evt.pos_y < koord[i][j].y + 13){

                    if(koord[i][j].t == 0){

                        if (getValue() % 2 == 0){

                            drawX(koord[i][j].x, koord[i][j].y);
                            koord[i][j].t = 1;
                            addValue();

                            winDetection(1);

                        } else if (getValue() % 2 == 1){

                            drawO(koord[i][j].x, koord[i][j].y);
                            koord[i][j].t = -1;
                            addValue();

                            winDetection(-1);
                        }
                    }
                }
            }
        }
    }
}

void EventHandler :: placedPieces(){            // FELRAJZOLJA AZOKAT A DARABOKAT AMIKET MAR LETETTEK A JATEKOSOK

    for(int i(0); i<20; i++){
        for(int j(0); j<20; j++){

            if(koord[i][j].t == 1){

                drawX(koord[i][j].x, koord[i][j].y);

            }else if(koord[i][j].t == -1){

                drawO(koord[i][j].x, koord[i][j].y);
            }
        }
    }
}

bool EventHandler :: gameOver(){            // SZOL HA BETELIK A PALYA

    for(int i(0); i<20; i++){
        for(int j(0); j<20; j++){

            if(koord[i][j].t == 0){

                return true;
            }
            if(koord[i][j].t == 3){
                win();
                return true;
            }
        }
    }

    over();
    return false;
}
