#include "graphics.hpp"
#include "Game.hh"
#ifndef EVENTHANDLER_HH
#define EVENTHANDLER_HH


class EventHandler : public Game
{
    public:
        EventHandler();
        virtual ~EventHandler();

        void buttons(event evt);
        void escape(event evt);
        void gamer();
        void action(event evt) override;
        void placedPieces();
        bool gameOver();

    protected:

    private:
};

#endif // EVENTHANDLER_HH
