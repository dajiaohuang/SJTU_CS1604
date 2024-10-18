#include <sstream>
#include <iomanip>
#include <cassert>
#include "engine.h"
#include "actions.h"
#include "units.h"
#include "algorithms.h"
#include "field.h"
using namespace std;

// Add units
bool addFootman(Field& field, bool sd, int row, int col)
{
    if (field.getUnit(row, col) != NULL)
        return false;

    Unit* ft = new Unit(FOOTMAN, sd, row, col);
    return field.setUnit(row, col, ft);
}

bool addKnight(Field& field, bool sd, int row, int col)
{
    if (field.getUnit(row, col) != NULL)
        return false;

    Unit* kn = new Unit(KNIGHT, sd, row, col);
    return field.setUnit(row, col, kn);
}

bool addArcher(Field& field, bool sd, int row, int col)
{
    if (field.getUnit(row, col) != NULL)
        return false;

    Unit* ar = new Unit(ARCHER, sd, row, col);
    return field.setUnit(row, col, ar);
}

bool performActionsPostAttack(ostream& os, istream&is, Field& field, Unit* u);
bool checkBounds(ostream& os, const Field& field, int row, int col);
bool readRowCol(const string& str, int& row, int& col);
bool queryRowCol(istream& is, ostream& os, int& row, int& col);
bool performActions(ostream& os, istream&is, Field& field, Unit* u);
bool checkWinning(ostream& os, Field& field);
bool performActionsPost(ostream& os, istream&is, Field& field, Unit* u);
// Main loop for playing the game
void play(Field& field, istream& is, ostream& os)
{
    bool side = true;
    int numTurns = 1;
    while (is)
    {

        os << endl;
        // Print the new map
        displayField(os, field);
        if(checkWinning(os,field))break;
        string player;
        if (side)
            player = "Player A";
        else
            player = "Player B";


        os << "Turn " << numTurns << " (" << player << ")" << endl;

        // Choose the source coordination
        os << "Please select a unit: ";
        int srow, scol;
        if (!queryRowCol(is, os, srow, scol))
            continue;
        if (!checkBounds(os, field, srow, scol))
            continue;

        // Select a unit
        Unit* u;
        SelectUResult sres = selectUnit(field, side, srow, scol, u);
        if (sres == SELECTU_NO_UNIT) {
            os << "No unit at (" << srow << ", " << scol << ")!" << endl;
            continue;
        } else if (sres == SELECTU_WRONG_SIDE) {
            os << "Unit at (" << srow << ", " << scol << ") is an enemy!" << endl;
            continue;
        }

        // Perform actions
        if (!performActions(os, is, field, u)){
            continue;
        }
        side = !side;
        numTurns++;
    }
}
//check winning
bool checkWinning(ostream& os, Field& field)
{
    bool A=1,B=0;
    for(int i=0;i<field.getHeight();i++){
        for(int j=0;j<field.getWidth();j++){
            Unit* u = field.getUnit(i,j);
            if(!u == NULL){
                bool side = u->getSide();
                A = A&&side;
                B = B||side;
            }
        }
    }
    if(A==1&&B==1){os<<"Congratulations! Player A has won!";return true;}
    if(A==0&&B==0){os<<"Congratulations! Player B has won!";return true;}
    return false;
}

// Check if (row, col) is in bounds
bool checkBounds(ostream& os, const Field& field, int row, int col)
{
    if (!field.inBounds(row, col)) {
        os << "(" << row << ", " << col << ") is out of bound" << endl;
        return false;
    }
    return true;
}

// Read row and column from the string
bool readRowCol(const string& str, int& row, int& col)
{
    stringstream ss(str);
    ss >> row >> col;
    if (ss)
        return true;
    else
        return false;
}

// Query row and column from input stream
bool queryRowCol(istream& is, ostream& os, int& row, int& col)
{
    string line;
    if (!getline(is, line)) {
        os << "Read line failed!" << endl;
        return false;
    }

    if (!readRowCol(line, row, col)) {
        os << "Incorrect input! "<< endl;
        return false;
    }

    return true;
}

// Display actions
void displayActions(ostream& os, const Vector<Action>& acts)
{
    for (int i = 0; i < acts.size(); i++) {
        os << i+1 << ".";
        switch (acts[i]) {
        case MOVE:
            os << "Move ";
            break;

        case SKIP:
            os << "Skip ";
            break;

        case ATTACK:
            os << "Attack ";
            break;
        case SHOOT:
            os << "Shoot ";
            break;
        default:
            assert(false);
        }
    }
    os << endl;
}


// Display a menu and query for the actions
bool queryAction(ostream& os, istream& is, Vector<Action>& acts, Action& res)
{
    int i;
    string line;
    getline(is, line);
    stringstream ss(line);
    ss >> i;
    if (!ss) return false;
    i--;
    if (i < 0 || i >= acts.size())
        return false;
    else {
        res = acts[i];
        return true;
    }
}

//Display a menu and query for the directions
bool queryDirection(ostream& os, istream& is, Directions& res)
{
    int i;
    string line;
    getline(is, line);
    stringstream ss(line);
    ss >> i;
    if (!ss) return false;
    i--;
    if (i < 0 || i >= 4)
        return false;
    else {
        res = Directions(i);
        return true;
    }
}
// Collection actions that can be performed by a unit
Vector<Action> collectActions(Unit* u)
{
    Vector<Action> acts = getActions(u);

    return acts;
}
Vector<Action> collectActionsPost(Unit* u)
{
    Vector<Action> acts = getActionsPost(u);

    return acts;
}
// Check if there is only skip action
bool isAllSkip(const Vector<Action>& acts)
{
    for (int i = 0; i < acts.size(); i++)
        if (acts[i] != SKIP)
            return false;
    return true;
}

// Convert field to costs
Grid<int> getFieldCosts(const Field& field)
{
    int h = field.getHeight();
    int w = field.getWidth();
    Grid<int> costs(h, w);

    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++) {
            costs[i][j] = 1;
            if (field.getUnit(i,j) != NULL) costs[i][j] = 999;
            else if (field.getTerrain(i,j) == 'W') costs[i][j] = 999;
            else if (field.getTerrain(i,j) == 'M') costs[i][j] = 999;
            else if (field.getTerrain(i,j) == 'F') costs[i][j] = 2;
        }
    }
    return costs;
}

// Perform the move action
bool performMove(ostream& os, istream& is, Field& field, Unit* u)
{
    // Display the reachable points
    Grid<bool> grd =
        searchReachable(getFieldCosts(field), u->getRow(), u->getCol(), u->getMovPoints());
    os << endl;
    displayField(os, field, grd);

    // Choose the target coordinate
    os << "Please enter your destination: ";
    int trow, tcol;
    if (!queryRowCol(is, os, trow, tcol))
        return false;
    if (!checkBounds(os, field, trow, tcol))
        return false;
    if (grd[trow][tcol] == false)
    {
        os<<"Cannot reach ("<<trow<<", "<<tcol<<")!"<<endl;
        return false;
    }
    // Move the target
    moveUnit(field, u, trow, tcol);
    return performActionsPost(os, is, field, u);
}

// Perform the attack action
bool performAttack(ostream& os, istream& is, Field& field, Unit* u)
{
    int srow,scol;
    srow = u->getRow();
    scol = u->getCol();

    // Choose the target direction
    os <<  "1.UP 2.DOWN 3.LEFT 4.RIGHT"<<endl
        <<"Please enter the direction: ";
    Directions direction;
    if (!queryDirection(os,is, direction)){
            os << "Incorrect input!" << endl;
        return false;
    }
    int trow,tcol;
    trow = srow;
    tcol = scol;

    switch(direction){
    case UP : trow-=1;break;
    case DOWN : trow += 1;break;
    case RIGHT : tcol +=1;break;
    case LEFT : tcol -=1;break;
    }

    if (!checkBounds(os, field, trow, tcol))
        return false;

    if (field.getUnit(trow , tcol) == NULL)
    {
        os<< "No unit to attack at ("<<trow<<", "<<tcol<<")"<<endl;
        return false;
    }
    // kill the target
    return field.killUnit(trow, tcol);
}
// Perform the shoot action
bool performShoot(ostream& os, istream& is, Field& field, Unit* u)
{
    int srow,scol;
    srow = u->getRow();
    scol = u->getCol();

    // Choose the target direction
    os <<  "1.UP 2.DOWN 3.LEFT 4.RIGHT"<<endl
        <<"Please enter the direction: ";
    Directions direction;
    if (!queryDirection(os,is, direction)){
            os << "Incorrect input!" << endl;
        return false;
    }
    int trow,tcol;
    trow = srow;
    tcol = scol;

    switch(direction){
    case UP : trow-=2;break;
    case DOWN : trow += 2;break;
    case RIGHT : tcol +=2;break;
    case LEFT : tcol -=2;break;
    }

    if (!checkBounds(os, field, trow, tcol))
        return false;

    if (field.getUnit(trow , tcol) == NULL)
    {
        os<< "No unit to attack at ("<<trow<<", "<<tcol<<")"<<endl;
        return false;
    }
    // kill the target
    return field.killUnit(trow, tcol);
}
// Perform the attack action
bool performAttackPost(ostream& os, istream& is, Field& field, Unit* u)
{
    int srow,scol;
    srow = u->getRow();
    scol = u->getCol();

    // Choose the target direction
    os <<  "1.UP 2.DOWN 3.LEFT 4.RIGHT"<<endl
        <<"Please enter the direction: ";
    Directions direction;
    if (!queryDirection(os,is, direction)){
            os << "Incorrect input!" << endl;
        return performActionsPostAttack(os,is,field,u);
    }
    int trow,tcol;
    trow = srow;
    tcol = scol;

    switch(direction){
    case UP : trow-=1;break;
    case DOWN : trow += 1;break;
    case RIGHT : tcol +=1;break;
    case LEFT : tcol -=1;break;
    }

    if (!checkBounds(os, field, trow, tcol))
        return performActionsPostAttack(os,is,field,u);


    if (field.getUnit(trow , tcol) == NULL)
    {
        os<< "No unit to attack at ("<<trow<<", "<<tcol<<")"<<endl;
        return performActionsPostAttack(os,is,field,u);
    }
    // kill the target


    return field.killUnit(trow, tcol);
}

bool performShootPost(ostream& os, istream& is, Field& field, Unit* u)
{
    int srow,scol;
    srow = u->getRow();
    scol = u->getCol();

    // Choose the target direction
    os <<  "1.UP 2.DOWN 3.LEFT 4.RIGHT"<<endl
        <<"Please enter the direction: ";
    Directions direction;
    if (!queryDirection(os,is, direction)){
            os << "Incorrect input!" << endl;
        return performActionsPostAttack(os,is,field,u);
    }
    int trow,tcol;
    trow = srow;
    tcol = scol;

    switch(direction){
    case UP : trow-=2;break;
    case DOWN : trow += 2;break;
    case RIGHT : tcol +=2;break;
    case LEFT : tcol -=2;break;
    }

    if (!checkBounds(os, field, trow, tcol))
        return performActionsPostAttack(os,is,field,u);


    if (field.getUnit(trow , tcol) == NULL)
    {
        os<< "No unit to attack at ("<<trow<<", "<<tcol<<")"<<endl;
        return performActionsPostAttack(os,is,field,u);
    }
    // kill the target


    return field.killUnit(trow, tcol);
}
// Perform actions
bool performActions(ostream& os, istream&is, Field& field, Unit* u)
{
    Vector<Action> acts = collectActions(u);
    if (isAllSkip(acts))
        return true;

    displayActions(os, acts);
    os << "Select your action: ";
    Action act;
    if (!queryAction(os, is, acts, act)) {
        os << "Invalid action!" << endl;
        return false;
    }

    switch(act) {
    case MOVE:
        return performMove(os, is, field, u);

    case SKIP:
        return true;

    case ATTACK:
        return performAttack(os, is, field, u);
    case SHOOT:
        return performShoot(os, is, field, u);
    default:
        os << "(Action not implemented yet)" << endl;
        return false;
    }

    assert (false);
}
//perform actions post moving
// Perform actions
bool performActionsPost(ostream& os, istream&is, Field& field, Unit* u)
{
    os<<endl;
    displayField(os, field);
    Vector<Action> acts = collectActionsPost(u);
    displayActions(os, acts);
    if (isAllSkip(acts))
        return true;
    os << "Select your action: ";
    Action act;
    if (!queryAction(os, is, acts, act)) {
        os << "Invalid action!" << endl;
        return performActionsPost(os, is, field, u);
    }

    switch(act) {

    case SKIP:
        return true;

    case ATTACK:
        return performAttackPost(os, is, field, u);
    case SHOOT:
        return performShootPost(os, is, field, u);
    default:
        os << "(Action not implemented yet)" << endl;
        return performActionsPost(os, is, field, u);
    }

    assert (false);
}

bool performActionsPostAttack(ostream& os, istream&is, Field& field, Unit* u)
{
    Vector<Action> acts = collectActionsPost(u);
    displayActions(os, acts);
    if (isAllSkip(acts))
        return true;
    os << "Select your action: ";
    Action act;
    if (!queryAction(os, is, acts, act)) {
        os << "Invalid action!" << endl;
        return performActionsPost(os, is, field, u);
    }

    switch(act) {

    case SKIP:
        return true;

    case ATTACK:
        return performAttackPost(os, is, field, u);
    case SHOOT:
        return performShootPost(os, is, field, u);
    default:
        os << "(Action not implemented yet)" << endl;
        return performActionsPost(os, is, field, u);
    }

    assert (false);
}
// Print the horizontal line
void printHLine(ostream& os, int n)
{
    os << "  ";
    for (int i = 0; i < n; i++)
        os << "+--";
    os << "+" << endl;
}

// Display the field on the out stream os
void displayField(ostream& os, const Field& field, const Grid<bool>& grd)
{
    int height = field.getHeight();
    int width = field.getWidth();

    // Print the x coordinates
    os << "  ";
    for (int i = 0; i < width; i++)
        os << ' ' << setw(2) << i;
    os << endl;

    printHLine(os, width);
    for (int i = 0; i < height; i++) {
        os << setw(2) << i;
        for (int j = 0; j < width; j++) {
            os << '|';
            Unit* u = field.getUnit(i,j);
            if (u != NULL)
                os << u->getSymbol();
            else if (grd.inBounds(i,j) && grd[i][j])
                os << ". ";
            else if (field.getTerrain(i,j) == 'W')
                os << "~~";
            else if (field.getTerrain(i,j) == 'M')
                os << "/\\";
            else if (field.getTerrain(i,j) == 'F')
                os << "$ ";
            else {
                os << "  ";
            }
        }
        os << '|' << endl;
        printHLine(os, width);
    }
    os << endl;
}

