#ifndef SOLVER_H
#define SOLVER_H
#include "Board.h"
#include <vector>
#include <queue>
using namespace std;

class Solver {
public:
    Solver(const Board& initial);          // find a solution to the initial board (using the A* algorithm)
    int moves();                           // min number of moves to solve initial board
    vector<Board> solution();              // sequence of boards in a shortest solution
private:
  Board CurrBoard;
  vector <Board> Solution_board;
  struct BoardNode {
    Board data;
    BoardNode* parents;
    int moves;
    struct CompareBoard{
      bool operator()(const BoardNode* one, const BoardNode* two){
        int Priority1 = (one->data).manhattan() + one->moves;
        int Priority2 = (two->data).manhattan() + two->moves;
        return Priority1 > Priority2;
      }
    };
  };


  priority_queue <BoardNode* , vector<BoardNode*>,  BoardNode::CompareBoard> Queue;
};

#endif
