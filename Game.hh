#include "graphics.hpp"
#include "Widget.hh"
#include "vector"
#ifndef GAME_HH
#define GAME_HH


class Game : public Widget
{
    public:
        Game();
        virtual ~Game();
        void field();
        void menu();
        void clearScreen();
        void reFresh();

        void drawO(int x, int y);
        void drawX(int x, int y);
        void active_1();
        void active_2();
        void button(string Name, int Num);
        void restart();
        void exitel();
        bool winDetection(int num);
        void win();
        void over();

        int getExit();
        int getValue();
        void addValue();
        string getB_1();
        string getB_2();
        string getP_1();
        string getP_2();

    protected:
        Point koord[20][20];

    private:

        int value = 0;
        int exit = 0;
        string Button_1 = "RESTART";
        string Button_2 = "EXIT";
        string Player_1 = "Sir Rounder";
        string Player_2 = "A Bitter-Sweet X";
};

#endif // GAME_HH
