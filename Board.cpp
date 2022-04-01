#include "Board.h"
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

Board::Board(const vector<vector<int> >& tiles){
  N = tiles[0].size();
  Tiles = tiles;
  solveboard.resize(N);
  for (int i = 0; i < N; i ++){
    solveboard[i].resize(N);
    for (int j = 0; j < N; j++){
      solveboard[i][j] = 1 + i * N + j;
    }
  }
  solveboard[N-1][N-1] = 0;
  //compute hamming distance
  for (int i = 0; i < N; i++){
    for(int j = 0; j < N;j++){
      if (Tiles[i][j] != 0){
        if (Tiles[i][j] != solveboard[i][j]){
            hamming_dist += 1;
        }
      }
    }
  }
    //compute manhattan distances
  for (int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(Tiles[i][j] != 0 ){
          if (Tiles[i][j] != solveboard[i][j]){
            int a = converse(solveboard[i][j]);
            int b = converse(Tiles[i][j]);
            int distance = abs(a - b);
            manhattan_dist += distance;
          }
        }
      }
    }
}

int Board::tileAt(int i, int j)const{
  if (Tiles[i][j] != 0){
     return Tiles[i][j];
   }
     return 0;
}

int Board::size() const{
  return N;
}

int Board::hamming() const{
    return hamming_dist;
}

int Board::converse(int index){
    int row = (index - 1) / N;
    int col = (index - 1) % N;
    return row + col;
}

int Board::manhattan()const{
    return manhattan_dist;
  }

bool Board::isGoal()const{
  return Tiles == solveboard;
}

int Board::inversions_count(int a, int b)const{
  int inversions = 0;
  bool check = false;
    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j ++){
        if(Tiles[i][j] == Tiles[a][b]){
          check = true;
        }
        if(check){
          break;
        }
        if(Tiles[i][j] > Tiles[a][b]){
          inversions ++;
        }
      }
    }
  return inversions;
}

bool Board::isSolvable()const{
  int row = 0;
  int sum = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if(Tiles[i][j] == 0){
        row = i;
      }
      else{
        int temp = inversions_count(i,j);
        sum = sum + temp;
      }
    }
  }
  if (N % 2 != 0){
    return (sum % 2 == 0);
  }
  else {
    return ((sum + row) % 2 == 1);
  }
}

bool Board::operator==(const Board& that) const{
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j ++){
      if (Tiles[i][j] != that.tileAt(i,j)){
        return false;
      }
    }
  }
  return true;
}

vector<Board> Board::neighbors() const{
  vector<Board> Neighbors;
  int row = 0;
  int col = 0;
  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      if (Tiles[i][j] == 0){
          row = i;
          col = j;
          break;
      }
    }

  }
    if (row-1 >= 0){
      vector< vector<int> > temp = Tiles;
      temp[row][col] = Tiles[row-1][col];
      temp[row-1][col] = 0;
      Board Copy(temp);
      Neighbors.push_back(Copy);
    }
    if (row+1 < N){
      vector< vector<int> > temp = Tiles;
      temp[row][col] = Tiles[row+1][col];
      temp[row+1][col] = 0;
      Board Copy(temp);
      Neighbors.push_back(Copy);
    }
    if (col-1 >= 0){
      vector< vector<int> > temp = Tiles;
      temp[row][col] = Tiles[row][col-1];
      temp[row][col-1] = 0;
      Board Copy(temp);
      Neighbors.push_back(Copy);
    }
    if (col+1 < N){
      vector< vector<int> > temp = Tiles;
      temp[row][col] = Tiles[row][col+1];
      temp[row][col+1] = 0;
      Board Copy(temp);
      Neighbors.push_back(Copy);
    }
  return Neighbors;
}

ostream& operator<<(ostream& out, const Board& b) {
    out << b.size() << endl;
    for (int i = 0; i < b.size(); i++) {
        for (int j = 0; j < b.size(); j++) {
            out << setw(2) << b.tileAt(i, j) << " ";
        }
        out << endl;
    }
    return out;
}
