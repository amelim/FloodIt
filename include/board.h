#pragma once

#include "libtcod.hpp"
#include "ColorCSP.h"
#include <vector>

using namespace std;
using namespace gtsam;

class Board
{
    protected:
        //Origins for rendering
        int x, y;

        int width, height;
        //Number of colors available;
        int k;

        //Our Discrete FactorGraph
        ColorCSP csp;
        //Ordering
        KeyOrdering ordering;
        //Discrete Values structure
        ColorCSP::Values values;

        vector<TCODColor> colors;
        vector<vector<TCODColor> > grid;
        //Tiles which are now officially active
        vector<vector<bool> > active;

        void buildGraph();

    public:
        //Default Constructor
        Board();
        Board(int x, int y, int w, int h, int k, vector<TCODColor> colors);
        int getX() { return x; }
        int getY() { return y; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        vector<vector<TCODColor> > getGrid() { return grid; }
        vector<vector<bool> > getActive() { return active; }
        vector<TCODColor> getColors() { return colors; }
        void updateBoard(TCODColor c);
        bool checkVictory();
};
