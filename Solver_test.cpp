#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
#include "Solver.h"
using namespace std;

int main(int argc, char* argv[]) {
    // create initial board from file
    string filename(argv[1]);
    ifstream in;
    in.open(filename);

    if (!in.is_open()) {
        cout << "File cannot be opened: " << filename << endl;
        return 1;
    }

    int N;
    in >> N;
    vector< vector<int> > tiles(N);
    for (int i = 0; i < N; i++) {
        tiles.at(i).resize(N);
        for (int j = 0; j < N; j++) {
            in >> tiles.at(i).at(j);
        }
    }
    in.close();

    Board initial(tiles);
    cout << initial;
    // check if puzzle is solvable; if so, solve it and output solution
    if (initial.isSolvable()) {
        Solver solver(initial);
        cout << "Minimum number of moves = " << solver.moves() << endl;
        for (Board board : solver.solution())
            cout << board << endl;
    }

    // // if not, report unsolvable
    else {
        cout << "Unsolvable puzzle" << endl;
    }
}
