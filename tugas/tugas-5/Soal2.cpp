/*
 Source: Kalicharan, Advanced Topics in C, p.157 no.18
 */

#include <iostream>
using namespace std;

int paths(int ax, int ay, int bx, int by) {
  if(ax == bx && ay == by) {
    return 1;
  } 
  if(ax > bx || ay > by) {    // out of grid
    return 0;
  }
  return paths(ax + 1, ay, bx, by) + paths(ax, ay + 1, bx, by);
}

int main() {
  int num_of_path = paths(0, 0, 2, 2);
  cout << num_of_path << endl;
  return 0;
}
