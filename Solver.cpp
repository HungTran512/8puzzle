#include "Solver.h"
#include "Board.h"
#include <vector>
#include <cmath>
#include <queue>
#include <iostream>
using namespace std;

Solver::Solver(const Board& initial):CurrBoard(initial){
  setbuf(stdout, NULL);
  if(CurrBoard.isGoal()==true){
    cout << "The board provided is already solved " << endl;
    return;
  }
  BoardNode* Curr_Node = new BoardNode{CurrBoard, nullptr, 0};
  for (auto neighbor : Curr_Node->data.neighbors()){
    Queue.push(new BoardNode{neighbor, Curr_Node, Curr_Node -> moves++});
  }
  while (Curr_Node->data.isGoal() != true){
    Curr_Node = Queue.top();
    Queue.pop();
    for (auto neighbor : Curr_Node->data.neighbors()) {
      if(!(neighbor == Curr_Node->parents->data)){
        Queue.push(new BoardNode{neighbor, Curr_Node, Curr_Node -> moves++});
      }
    }
  }
  //track back.
  while(Curr_Node->parents != nullptr){
    Solution_board.push_back(Curr_Node->data);
    Curr_Node = Curr_Node->parents;
  }
  //revere the solution board to get the target board
  reverse(Solution_board.begin(), Solution_board.end());
}


// return shortes path.
int Solver::moves(){
  return Solution_board.size();
}
// return the solution which is a vector of boards from root to the goal board.
vector<Board> Solver::solution(){
  return Solution_board;
}
