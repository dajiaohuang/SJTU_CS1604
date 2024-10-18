#include <string>
#include <cassert>
#include <iomanip>
#include "field.h"
#include "units.h"
using namespace std;


/* Battle field */

// Constructor
Field::Field(int h, int w)
    : units(h, w),terrain(h, w)
{
    assert (h > 0 && h <=20 && w > 0 && w <= 20);
}

// Get the height of the field
int Field::getHeight() const
{
    return units.numRows();
}

// Get the width of the field
int Field::getWidth() const
{
    return units.numCols();
}

// In bounds check
bool Field::inBounds(int row, int col) const
{
    return units.inBounds(row, col);
}

// Get the unit at row and col
Unit* Field::getUnit(int row, int col) const
{
    assert (units.inBounds(row, col));

    return units[row][col];
}

//Get the terrain at row and col
char Field::getTerrain(int row, int col) const
{
    assert (terrain.inBounds(row, col));
    return terrain[row][col];
}

// Set a new unit at row and col
// Return false if the coordinate is already occupied
// or unreachable
bool Field::setUnit(int row, int col, Unit* u)
{
    assert (units.inBounds(row, col));
    assert (getTerrain(row, col) != 'W');
    assert (getTerrain(row, col) != 'M');
    if (units[row][col] == NULL) {
        u->setCoord(row, col);
        units[row][col] = u;
        return true;
    }
    else
        return false;
}

//set a new terrain
bool Field::setTerrain(int row, int col, char ter)
{
    assert (terrain.inBounds(row, col));

    terrain[row][col] = ter;
    return true;
}

// Move a unit to a different coordinate
// Return false if the source does not exist or
// the target coordinate is already occupied or
// unreachable
bool Field::moveUnit(int srow, int scol, int trow, int tcol)
{
    assert (units.inBounds(srow, scol));
    assert (units.inBounds(trow, tcol));
    assert (units[trow][tcol] == NULL);
    Unit* u = getUnit(srow, scol);
    setUnit(trow, tcol, u);
    units[srow][scol] = NULL;
    return true;
}
//kill
bool Field::killUnit(int row, int col){
    assert (units.inBounds(row, col));
    assert (units[row][col] != NULL);
    delete units[row][col];
    units[row][col] = NULL;
    return true;
}

// Reclaim all the units
Field::~Field()
{
    for (int i = 0; i < units.numRows(); i++)
    for (int j = 0; j < units.numCols(); j++)
        if (units[i][j] != NULL)
            delete units[i][j];
}
