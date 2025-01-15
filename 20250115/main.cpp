#include <iostream>
#include <vector>

using namespace std;

int R, C;
vector<string> og_map;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool isSea(int r, int c) {
  int nr, nc;
  int count = 0;

  for (int i = 0; i < 4; i++) {
    nr = r + dy[i];
    nc = c + dx[i];

    if (nr < 0 || nr >= R || nc < 0 || nc >= C || og_map[nr][nc] == '.')
      count++;
  }

  return count >= 3;
}

int main() {
  cin >> R >> C;

  og_map.resize(R);
  for (int r = 0; r < R; r++) {
    cin >> og_map[r];
  }

  int sr = R, sc = C, er = -1, ec = -1;
  vector<vector<char>> new_map(R, vector<char>(C, '.'));

  for (int r = 0; r < R; r++) {
    for (int c = 0; c < C; c++) {
      new_map[r][c] = (og_map[r][c] == 'X' && isSea(r, c)) ? '.' : og_map[r][c];

      if (new_map[r][c] == 'X') {
        sr = sr > r ? r : sr;
        er = er < r ? r : er;

        sc = sc > c ? c : sc;
        ec = ec < c ? c : ec;
      }
    }
  }

  for (int r = sr; r <= er; r++) {
    for (int c = sc; c <= ec; c++) {
      cout << new_map[r][c];
    }
    cout << endl;
  }

  return 0;
}