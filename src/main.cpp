/*
 * Main executable class for FloodIt
 * Requires: libtcod-1.5.1
 */

#include "libtcod.hpp"
#include "board.h"
#include <stdio.h>
#include <iostream>

#define GAME_SCREEN_WIDTH 10
#define GAME_SCREEN_HEIGHT 10
#define GAME_SCREEN_X 19 
#define GAME_SCREEN_Y 1
#define COLOR_LIST_Y 5

//This is the console which will render the game board
//TODO: Width and Height are defined by the game board size
TCODConsole gameConsole(GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT);
Board* gameboard;
vector<vector<TCODColor> > gamegrid;
vector<TCODColor> gamecolors;
int width, height;


void init()
{
    gameboard = new Board();
    gamegrid = gameboard->getGrid();
    width = gameboard->getWidth();
    height = gameboard->getHeight();
    gamecolors = gameboard->getColors();

    gameConsole.setDefaultBackground(TCODColor::red);
}
void render()
{
    gameConsole.clear();

    //Render the board to the gameconsole
    for(int i=0; i < width; i++)
        for(int j=0; j < height; j++)
            gameConsole.setCharBackground(i, j, gamegrid[i][j]);

    //Render the color options to the root console
    TCODConsole::root->print(5, 2, "Colors");
    for(int i=0; i< gamecolors.size(); i++)
    {
        TCODConsole::root->setCharBackground(2, COLOR_LIST_Y+(i*5), gamecolors[i]);
        TCODConsole::root->setCharBackground(2, COLOR_LIST_Y+(i*5)+1, gamecolors[i]);
        TCODConsole::root->setCharBackground(3, COLOR_LIST_Y+(i*5), gamecolors[i]);
        TCODConsole::root->setCharBackground(3, COLOR_LIST_Y+(i*5)+1, gamecolors[i]);
    }

    TCODConsole::blit(&gameConsole,0,0,GAME_SCREEN_WIDTH, GAME_SCREEN_HEIGHT,
            TCODConsole::root,GAME_SCREEN_X,GAME_SCREEN_Y);
}
void update()
{

}

int main(int argc, char** argv)
{
    TCODConsole::initRoot(60, 45,"Flood It", false, TCOD_RENDERER_SDL); 
    TCODConsole::root->setAlignment(TCOD_CENTER);
    TCOD_key_t k = {TCODK_NONE,0};
    TCOD_mouse_t mouse;

    init();

    while(!TCODConsole::isWindowClosed())
    {
        render();
        TCODConsole::flush();
        //TODO:Do we want to wait?
        TCODSystem::checkForEvent((TCOD_event_t)TCOD_EVENT_KEY_PRESS|TCOD_EVENT_MOUSE,&k,&mouse);
        if(mouse.lbutton_pressed)
        {
            for(int i=0; i < gamecolors.size(); i++)
            {
                if(mouse.cx > 1 && mouse.cx <= 3)
                    if(mouse.cy == COLOR_LIST_Y+(i*5) ||
                       mouse.cy == COLOR_LIST_Y+(i*5)+1)
                    {
                        gameboard->updateBoard(gamecolors[i]);
                        gamegrid = gameboard->getGrid();
                    }
            }
        }
            
    }
    return 0;
}
