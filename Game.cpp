#include "Widget.hh"
#include "Game.hh"

    // RAJZOLGATASOK ES EGYEB EVENTET NEM IGENYLO DOLGOK //


Game::~Game()
{
    //dtor
}

Game :: Game(){         // FELTOLTI A MATRIXOT
                        // a tablazat kis negyzeteinek koordinatai es az allapota van benne
    value = 1;          // -> o meg itt szamolja hany elem lett lerakva

    for(int i(0); i<20; i++){
        for(int j(0); j<20; j++){

            koord[i][j].x = 25 + j*30;
            koord[i][j].y = 25 + i*30;
            koord[i][j].t = 0;
        }
    }
}

void Game :: field() {      // KIRAJZOLJA A PALYAT

    for(int i(10); i<610; i+=30){
        for(int j(10); j<610; j+=30){

            gout << color(80, 180, 180)
                 << move_to(i, j)
                 << box(25, 25);
        }
    }
}

void Game :: menu(){        // KIIRJA A MENUHOZ TARTOZO DOLGOKAT

    gout << color(80, 180, 180)
         << move_to(780 - gout.twidth(Button_1)/2, 110)
         << text(Button_1)
         << move_to(780 - gout.twidth(Button_2)/2, 210)
         << text(Button_2)
         << move_to(780 - gout.twidth(Player_1)/2, 410)
         << text(Player_1)
         << move_to(780 - gout.twidth(Player_2)/2, 460)
         << text(Player_2);
}

void Game :: clearScreen() {            // EZ MOST A MAINBEN NEM LEHET EZERT ITT VAN :D

    gout << move_to(0, 0)
         << color(0, 0, 0)
         << box(930, 620);
}

void Game :: reFresh(){

    gout << refresh;
}

                    // KIRAJZOLNIVALO DOLGOK //

void Game :: drawO(int x,int y){

    for(int i(0);i<100;i++){
        for(int j(0);j<100;j++){
            if((i-50)*(i-50)+(j-50)*(j-50) <= 155 && (i-50)*(i-50)+(j-50)*(j-50) >= 45)

                gout << move_to(i+x-53,j+y-53)
                     << color(255, 255, 255)
                     << dot;
        }
    }
}

void Game :: drawX(int x, int y){

    for(int i(10);i<15;i++){
        for(int j(10);j<15;j++){

            gout << color(255, 255, 255)
                 << move_to(x-i, y-j)
                 << line_to(x+j-5, y+i-5)
                 << move_to(x+i-5, y-j)
                 << line_to(x-j, y+i-5);
        }
    }
}

           // GOMBOKHOZ TARTOZO TORTENESEK //

void Game :: button(string buttonName, int buttonNum){

        gout << color(235, 65, 50)
             << move_to(780 - gout.twidth(buttonName)/2, 100*buttonNum + 10)
             << text(buttonName);
}

void Game :: restart(){

            clearScreen();
            menu();
            field();

        for(int i(0); i<20; i++){
            for(int j(0); j<20; j++){

                koord[i][j].t = 0;
            }
        }
}

void Game :: exitel(){

         exit++;
}

            // AKTUALIS JATEKOST JELZI MAS SZINNEL //

void Game :: active_1(){

        gout << color(235, 65, 50)
             << move_to(780 - gout.twidth(Player_1)/2, 410)
             << text(Player_1)
             << color(80, 180, 180)
             << move_to(780 - gout.twidth(Player_2)/2, 460)
             << text(Player_2);
}

void Game :: active_2(){

        gout << color(235, 65, 50)
             << move_to(780 - gout.twidth(Player_2)/2, 460)
             << text(Player_2)
             << color(80, 180, 180)
             << move_to(780 - gout.twidth(Player_1)/2, 410)
             << text(Player_1);
}

bool Game :: winDetection(int num){            // ERZEKELI MIKOR OSSZEGYULIK VALAKINEK AZ 5 IZE

    int counter;

    for(int i(0); i<20; i++){
        for(int j(0); j<20; j++){

            counter = 0;

            for(int k(0); k<5; k++){

                if(koord[i][j+k].t == num){
                    counter++;
                }
                    if(counter == 5){
                        win();
                        return true;
                    }
            } counter = 0;

            for(int k(0); k<5; k++){

                if(koord[i+k][j].t == num){
                    counter++;
                }
                    if(counter == 5){
                        win();
                        return true;
                    }
            } counter = 0;

            for(int k(0); k<5; k++){

                if(koord[i+k][j+k].t == num){
                    counter++;
                }
                    if(counter == 5){
                        win();
                        return true;
                    }
            } counter = 0;

            for(int k(0); k<5; k++){

                if(koord[i+k][j-k].t == num){
                    counter++;
                }
                    if(counter == 5){
                        win();
                        return true;
                    }
            }
        }
    }
    return false;
}

void Game :: win(){            // A GYOZTESNEK PARTY HANGULATOT TEREMT

        string winner;

    if(value % 2 == 0){
        winner = Player_1;
    }else if(value % 2 == 1){
        winner = Player_2;
    }
        gout << color(255, 200, 0)
         << move_to(780 - gout.twidth("THE WINNER IS: ")/2, 310)
         << text("THE WINNER IS: ")
         << move_to(780 - gout.twidth(winner)/2, 310 + gout.cascent()*2)
         << text(winner);

    for(int i(10); i<610; i+=30){
        for(int j(10); j<610; j+=30){

            int r = rand() % 255;
            int g = rand() % 255;
            int b = rand() % 255;

            gout << color(r, g, b)
                 << move_to(i, j)
                 << box(25, 25);
        }
    }
    for(int i(0); i<20; i++){
        for(int j(0); j<20; j++){

            koord[i][j].t = 3;
        }
    }
}

void Game :: over(){            // HA BETELIK A PALYA SZOL ES NEM ENGED TOBBET RAKNI

    gout << color(255, 200, 0)
         << move_to(780 - gout.twidth("GAME OVER")/2, 310)
         << text("GAME OVER");

    for(int i(10); i<610; i+=30){
        for(int j(10); j<610; j+=30){

            gout << color(255, 200, 0)
                 << move_to(i, j)
                 << box(25, 25);
        }
    }
    for(int i(0); i<20; i++){
        for(int j(0); j<20; j++){

            koord[i][j].t = 5;
        }
    }
}

            // GETTEREK //

int Game :: getExit(){
    return exit;
}

int Game :: getValue(){
    return value;
}

void Game :: addValue(){
    value++;
}


string Game :: getB_1(){
    return Button_1;
}

string Game :: getB_2(){
    return Button_2;
}

string Game :: getP_1(){
    return Player_1;
}

string Game :: getP_2(){
    return Player_2;
}
