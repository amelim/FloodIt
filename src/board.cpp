#include "board.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>
#include <list>

#define DEBUG 0 

Board::Board()
{
    //Xy offsets from top left corner of the board
    x = 19;
    y = 1;
    width = 20;
    height = 20;
    k = 3;
    colors.push_back(TCODColor::red);
    colors.push_back(TCODColor::blue);
    colors.push_back(TCODColor::yellow);
    srand(time(0));

    //Find our random colors
    for(int i=0; i<width; i++)
    {
        vector<TCODColor> row;
        vector<bool> brow;
        for(int j=0; j<height; j++)
        {
           row.push_back(colors[rand() % 3]);
           brow.push_back(false);
        }
        grid.push_back(row);
        active.push_back(brow);
    }
    active[0][0] = true;
}

Board::Board(int x, int y, int w, int h, int k, vector<TCODColor>colors)
{
    this->x = x;
    this->y = y;
    width = w;
    height = h;
    this->k = k;
    this->colors = colors;
    
    srand(time(0));

    //Find our random colors
    for(int i=0; i<width; i++)
    {
        vector<TCODColor> row;
        vector<bool> brow;
        for(int j=0; j<height; j++)
        {
           row.push_back(colors[rand() % 3]);
           brow.push_back(false);
        }
        grid.push_back(row);
        active.push_back(brow);
    }
    active[0][0] = true;

}

bool Board::checkVictory()
{
    TCODColor vcolor = grid[0][0];
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++)
            if(grid[i][j] != vcolor)
                return false;

    return true;
}

void Board::updateBoard(TCODColor c)
{
    bool active[width][height];
    for(int i=0; i<width; i++)
        for(int j=0; j<height; j++)
            active[i][j]=false;

    TCODColor old = grid[0][0];
    if(c == old)
        return;
    list<int> queue;
    //XY origin
    queue.push_back(0);
    queue.push_back(0);
    int curx, cury;
    while(queue.size()!=0)
    {

        //Dequeue the next tile
        curx = queue.front();
        queue.pop_front();
        cury = queue.front();
        queue.pop_front();
        grid[curx][cury] = c;
        if(DEBUG)
        {
            cout << "Current tile x: " << curx << endl;
            cout << "Current tile y: " << cury << endl;
        }
        //Check all surrounding tiles and add them if they are the old color
        //left check
        if(curx > 0)
            if(grid[curx-1][cury] == old && !active[curx-1][cury]) 
            {
                queue.push_back(curx-1);
                queue.push_back(cury);
                active[curx-1][cury]=true;
                if(DEBUG)
                {
                    cout << "Adding x: " << curx-1 << endl;
                    cout << "Adding y: " << cury << endl;
                }
            }
        //right check
        if(curx < width-1)
            if(grid[curx+1][cury] == old && !active[curx+1][cury])
            {
                queue.push_back(curx+1);
                queue.push_back(cury);
                active[curx+1][cury]=true;
                if(DEBUG)
                {
                    cout << "Adding x: " << curx+1 << endl;
                    cout << "Adding y: " << cury << endl;
                }
            }

        //downcheck
        if(cury < height-1)
            if(grid[curx][cury+1] == old && !active[curx][cury+1])
            {
                queue.push_back(curx);
                queue.push_back(cury+1);
                active[curx][cury+1]=true;
                if(DEBUG)
                {
                    cout << "Adding x: " << curx << endl;
                    cout << "Adding y: " << cury+1 << endl;
                }
            }
        //up check
        if(cury > 0)
            if(grid[curx][cury-1] == old && !active[curx][cury-1])
            {
                queue.push_back(curx);
                queue.push_back(cury-1);
                active[curx][cury-1]=true;
                if(DEBUG)
                {
                    cout << "Adding x: " << curx << endl;
                    cout << "Adding y: " << cury-1 << endl;
                }
            }
    }
}
