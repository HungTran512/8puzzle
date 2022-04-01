#include <iostream>
#include <fstream>
#include <vector>
#include "Board.h"
#include <vector>
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
    Board Hung(tiles);
    cout << "size: " << Hung.size() << endl;
    cout << "hamming: " << Hung.hamming()<< endl;
    cout << "manhattan: " << Hung.manhattan() << endl;
    if(Hung.isSolvable() == 0){
      cout << "unsolvable" << endl;
    }
    else{cout << "solvable" << endl;}
    cout << "inversions % 2: " << Hung.isSolvable() << endl;
    cout << "is goal ? " << Hung.isGoal()<< endl;
  // for(auto x : Hung){
  //   cout << x << endl;
  // }
    return 0;
  }
