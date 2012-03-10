#include "board.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

Board::Board()
{
    //Xy offsets from top left corner of the board
    x = 19;
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

void Board::updateBoard(TCODColor c)
{
    TCODColor old = grid[0][0];
    bool flags [width][height];
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
            flags[i][j] = false;
    flags[0][0] = true;
    grid[0][0] = c;
    for(int i = 0; i < width; i++)
        for(int j = 0; j < height; j++)
        {
            if(j==0 && i > 0)
                if(flags[i-1][j] == true || flags[i+1][j] == true || flags[i][j+1] == true)
                    if(grid[i][j] == old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            else if(i==0 && j > 0)
                if(flags[i][j-1] == true || flags[i][j+1] == true || flags[i+1][j] == true) 
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            else if(j == height-1)
                if(flags[i-1][j] == true || flags[i+1][j] == true || flags[i][j-1] == true) 
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            else if(i == width-1)
                if(flags[i][j-1] == true || flags[i][j+1] == true || flags[i-1][j] == true) 
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            else if(i == 0 && j == 0){}
            else
                if(flags[i-1][j] == true || flags[i][j-1] == true
                        || flags[i+1][j] == true || flags[i][j+1] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
        }
}
