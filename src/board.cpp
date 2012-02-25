#include "board.h"
#include <stdlib.h>
#include <ctime>

Board::Board()
{
    //Xy offsets from top left corner of the board
    x = 39;
    y = 1;
    width = 40;
    height = 40;
    k = 3;
    colors.push_back(TCODColor::red);
    colors.push_back(TCODColor::blue);
    colors.push_back(TCODColor::yellow);
    srand(time(0));

    //Find our random colors
    for(int i=0; i<width; i++)
    {
        vector<TCODColor> row;
        for(int j=0; j<height; j++)
           row.push_back(colors[rand() % 3]);
        grid.push_back(row);
    }
}
