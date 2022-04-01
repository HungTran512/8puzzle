#ifndef BOARD_H
#define BOARD_H
#include <vector>
#include <iostream>
using namespace std;

class Board {
public:
    Board(const vector< vector<int> >& tiles);                  // construct a board from an N-by-N array of tiles
                                                                // (where tiles[i][j] = tile at row i, column j)
    int tileAt(int i, int j) const;                             // return tile at row i, column j (or 0 if blank)
    int size() const;                                           // board size N
    int hamming() const;                                        // number of tiles out of place
    int manhattan() const;                                      // sum of Manhattan distances between tiles and goal
    bool isGoal() const;                                        // is this board the goal board?
    bool isSolvable() const;                                    // is this board solvable?
    bool operator==(const Board& that) const;                   // does this board equal that board?
    vector<Board> neighbors() const;                            // all neighboring boards
    friend ostream& operator<<(ostream& out, const Board& b);   // displays this board
private:
    vector< vector<int> > Tiles;
    vector< vector<int> > solveboard;                           // the goal board
    int converse(int index);                                    // converse the index to the sum of row and column in the solveboard
    int N;                                                      //size
    int hamming_dist = 0;
    int manhattan_dist = 0;
    int inversions_count(int a, int b)const;
};


#endif
