#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include "field.h"
#include "units.h"
#include "engine.h"
using namespace std;
Field* loadMap(istream& is);
int main()
{
    /*string filename = "field.txt";
    ofstream ofs;
    ofs.open(filename.c_str());
    if (!ofs) {
        cout << "Cannot open the file: " << filename << endl;
        return -1;
    }

    Field f(11, 11);

    // Set units
    addFootman(f, true, 2, 0);
    addFootman(f, true, 2, 1);
    addFootman(f, true, 2, 2);
    addFootman(f, true, 2, 7);

    addFootman(f, false, 7, 4);
    addFootman(f, false, 8, 3);
    addFootman(f, false, 7, 3);
    addFootman(f, false, 9, 5);


    displayField(cout, f);

    play(f, cin, cout);

    ofs.close();*/
    Field* f = loadMap(cin);
    play(*f, cin, cout);
    return 0;
}

Field* loadMap(istream& is)
{
    int M,N,NT,NU;
    string line;
    getline(is, line);
    stringstream ss(line);
    ss>>M>>N>>NT>>NU;
    Field* f = new Field(M, N);
    for(int i=0;i<NT;i++){
        int R,C;
        char T;
        string line;
        getline(is, line);
        stringstream ss(line);
        ss>>R>>C>>T;
        assert(f->setTerrain(R,C,T));
    }
    for(int i=0;i<NU;i++){
        int R,C;
        char S;
        string U;
        string line;
        getline(is, line);
        stringstream ss(line);
        ss>>R>>C>>S>>U;
        if (U == "FT") addFootman(*f, S == 'A', R, C );
        else if (U == "KN") addKnight(*f, S == 'A', R, C );
        else if (U == "AR") addArcher(*f, S == 'A', R, C );
    }
    return f;
}
