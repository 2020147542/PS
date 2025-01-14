#include <iostream>
#include <vector>
#define up 0
#define right 1
#define down 2
#define left 3

using namespace std;

int C, R, K;
vector<vector<bool>> seats;
short dx[4] = {0, 1, 0, -1};
short dy[4] = {-1, 0, 1, 0};

void dfs(int row, int col, int count, short direction) {
  if (count == K) {
    cout << col + 1 << " " << R - row << endl;
    return;
  }

  seats[row][col] = true;

  int n_row = row + dy[direction];
  int n_col = col + dx[direction];
  short n_direction = direction;

  if (direction == up) {
    if (n_row == -1 || seats[n_row][n_col]) n_direction = right;
  } else if (direction == right) {
    if (n_col == C || seats[n_row][n_col]) n_direction = down;
  } else if (direction == down) {
    if (n_row == R || seats[n_row][n_col]) n_direction = left;
  } else if (direction == left) {
    if (n_col == -1 || seats[n_row][n_col]) n_direction = up;
  }

  n_row = row + dy[n_direction];
  n_col = col + dx[n_direction];
  dfs(n_row, n_col, count + 1, n_direction);
}

int main() {
  cin >> C >> R >> K;

  seats.resize(R, vector<bool>(C));

  if (K > C * R) {
    cout << 0 << endl;
  } else {
    dfs(R - 1, 0, 1, up);
  }

  return 0;
}