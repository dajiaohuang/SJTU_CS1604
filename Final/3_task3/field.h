#ifndef FIELD_H_INCLUDED
#define FIELD_H_INCLUDED

#include <ostream>
#include <Grid.h>

// Forward declaration of the class of units
class Unit;


/* Battle field */
class Field {
public:
    // Constructor
    Field(int h, int w);

    // Get the height and width of the field
    int getHeight() const;
    int getWidth() const;

    // Check if the row and column is in bounds
    bool inBounds(int row, int col) const;

    // Display the field on the out stream os
    void display(std::ostream& os, const Grid<bool>& grd = Grid<bool>()) const;

    // Get the unit at row and col
    Unit* getUnit(int row, int col) const;

    //Get the terrain at row and col
    char getTerrain(int row, int col) const;

    // Set a new unit at row and col
    // Return false if the coordinate is already occupied
    bool setUnit(int row, int col, Unit* u);

    //set a new terrain
    bool setTerrain(int row, int col, char terrain);

    // Move a unit to a different coordinate
    // Return false if the target coordinate is already occupied
    bool moveUnit(int srow, int scol, int trow, int tcol);

    bool killUnit(int row, int col);
    // Destructor
    ~Field();

private:
    // Store the units
    Grid<Unit*> units;
    Grid<char> terrain;
};

#endif // FIELD_H_INCLUDED
