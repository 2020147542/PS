#include <iostream>
#include <vector>

using namespace std;

vector<vector<short>> arr;
vector<pair<short, short>> emptyIdx;
bool done = false;

vector<short> isPossible(short row, short col) {
  vector<bool> list(10, true);

  for (int i = 0; i < 9; i++) {
    list[arr[row][i]] = false;
  }

  for (int i = 0; i < 9; i++) {
    list[arr[i][col]] = false;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      list[arr[row - (row % 3) + i][col - (col % 3) + j]] = false;
    }
  }

  vector<short> possible;
  for (int i = 1; i <= 9; i++) {
    if (list[i]) {
      possible.push_back(i);
    }
  }

  return possible;
}

void backtracking(int i) {
  if (i == emptyIdx.size()) {
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        cout << arr[i][j] << " ";
      }
      cout << endl;
    }

    done = true;
    return;
  }

  short row = emptyIdx[i].first;
  short col = emptyIdx[i].second;
  vector<short> numbers = isPossible(row, col);

  if (numbers.empty()) return;

  for (short num : numbers) {
    arr[row][col] = num;
    backtracking(i + 1);

    if (done) return;
    arr[row][col] = 0;
  }
}

int main() {
  arr.resize(9, vector<short>(9));

  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cin >> arr[i][j];

      if (arr[i][j] == 0) {
        emptyIdx.push_back({i, j});
      }
    }
  }

  backtracking(0);

  return 0;
}