#include "libtcod.hpp"
#include <vector>
using namespace std;
class Board
{
    protected:
        //Origins for rendering
        int x, y;

        int width, height;
        //Number of colors available;
        int k;

        vector<TCODColor> colors;
        vector<vector<TCODColor> > grid;
    public:
        //Default Constructor
        Board();
        Board(int x, int y, int w, int h, int k);
        int getX() { return x; }
        int getY() { return y; }
        int getWidth() { return width; }
        int getHeight() { return height; }
        vector<vector<TCODColor> > getGrid() { return grid; }
        vector<TCODColor> getColors() { return colors; }
        void updateBoard(TCODColor c);
};
