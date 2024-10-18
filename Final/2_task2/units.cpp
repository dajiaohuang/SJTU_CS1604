#include "units.h"
#include "field.h"
#include <cassert>
using namespace std;

/* Unit */

Unit::Unit(UnitType t, bool sd, int row, int col)
    : type(t), side(sd), urow(row), ucol(col)
    {}

bool Unit::getSide() const
{
    return side;
}

int Unit::getMovPoints() const
{
    switch (type) {
    case FOOTMAN:
    case ARCHER:
        return 3;

    case KNIGHT:
        return 5;
    }
}

// Get the coordinate of the current unit
int Unit::getRow() const
{
    return urow;
}

int Unit::getCol() const
{
    return ucol;
}

// Set the coordinates
void Unit::setCoord(int row, int col)
{
    urow = row;
    ucol = col;
}

// Function for symbols
string getSymbolFootman(bool side)
{
    if (side)
        return "FT";
    else
        return "ft";
}

string getSymbolKnight(bool side)
{
    if (side)
        return "KN";
    else
        return "kn";
}

string getSymbolArcher(bool side)
{
    if (side)
        return "AR";
    else
        return "ar";
}

// Get the symbol of the unit
string Unit::getSymbol() const
{
    switch (type) {
    case FOOTMAN:
        return getSymbolFootman(side);

    case ARCHER:
        return getSymbolArcher(side);

    case KNIGHT:
        return getSymbolKnight(side);
    }
    assert (false);
}



