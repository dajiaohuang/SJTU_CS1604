#ifndef ENGINE_H_INCLUDED
#define ENGINE_H_INCLUDED

#include <iostream>
#include "field.h"

// Add units
bool addFootman(Field& field, bool side, int row, int col);
bool addKnight(Field& field, bool side, int row, int col);
bool addArcher(Field& field, bool side, int row, int col);
// Main loop for playing the game
void play(Field& field, std::istream& is, std::ostream& os);

// Display the battle field
void displayField(std::ostream& os, const Field& field,
                  const Grid<bool>& grd = Grid<bool>());

#endif // ENGINE_H_INCLUDED
