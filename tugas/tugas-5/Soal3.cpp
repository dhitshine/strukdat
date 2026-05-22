/*
 Source: Kalicharan, Advanced Topics in C, p.157 no.19
 */

#include <iostream>
#include <cmath>
using namespace std;

int board[8];

bool safe(int row, int col) {
  for(int i = 0; i < row; i++) {
    if(board[i] == col) {
      return false;
    }
    if(abs(i - row) == abs(board[i] - col)) {
      return false;
    }
  }
  return true;
}

void print() {
  for(int i = 0; i < 8; i++) {
    for(int j = 0; j < 8; j++) {
      if(board[i] == j) {
        cout << "Q ";
      }else {
        cout << ". ";
      }
    }
    cout << endl;
  }
  cout << endl;
}

void solve(int row) {
  if(row == 8){
    print();
    return;
  }
  for(int col = 0; col < 8; col++) {
    if(safe(row, col)) {
      board[row] = col;
      solve(row + 1);
    }
  }
}

int main() {
  solve(0);
  return 0;
}
