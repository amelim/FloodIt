#include "board.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

Board::Board()
{
    //Xy offsets from top left corner of the board
    x = 19;
    y = 1;
    width = 10;
    height = 10;
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
            //Edge case 1 Top Edge
            if(j==0 && i > 0 && i < (width-1))
            {
                if(flags[i-1][j] == true || flags[i+1][j] == true || flags[i][j+1] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Edge case 2 Left Edge
            else if(i==0 && j > 0 && j < (height-1))
            {
                if(flags[i][j-1] == true || flags[i+1][j] == true || flags[i][j+1] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Edge case 3 Bottom Edge
            else if(j==(height-1) && i > 0 && i < (width-1))
            {
                if(flags[i][j-1] == true || flags[i+1][j] == true || flags[i-1][j] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Edge case 4 Right Edge
            else if(i==(width-1) && j > 0 && j < (height -1))
            {
                if(flags[i][j-1] == true || flags[i-1][j] == true || flags[i][j+1] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Corner case 1 Top Right
            else if(i==(width-1) && j == 0)
            {
                if(flags[i][j+1] == true || flags[i-1][j] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Corner case 2 Bottom Left
            else if(i==0 && j==(height -1))
            {
                if(flags[i][j-1] == true || flags[i+1][j] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Corner case 3 Bottom Right
            else if(i==(width-1) && j==(height -1))
            {
                if(flags[i][j-1] == true || flags[i-1][j] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
            //Corner case 4
            else if(j==0 && i==0) {}
            else
            {
                if(flags[i-1][j] == true || flags[i][j-1] == true || flags[i+1][j] == true || flags[i][j+1] == true)
                    if(grid[i][j]==old)
                    {
                        grid[i][j] = c;
                        flags[i][j] = true;
                    }
            }
        }
}
