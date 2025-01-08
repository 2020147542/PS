#include <iostream>
#include <set>

using namespace std;

short nx[4] = {0, 0, -1, 1};
short ny[4] = {-1, 1, 0, 0};

char arr[5][5];
set<string> sixDigits;

void findSixDigits(short row, short col, string result) {
  if (result.size() == 6) {
    sixDigits.insert(result);
    return;
  }

  for (int i = 0; i < 4; i++) {
    short nr = row + ny[i];
    short nc = col + nx[i];

    if (nc < 5 && nc >= 0 && nr < 5 && nr >= 0) {
      findSixDigits(nr, nc, result + arr[nr][nc]);
    }
  }
}

int main() {
  for (short i = 0; i < 5; i++) {
    for (short j = 0; j < 5; j++) {
      cin >> arr[i][j];
    }
  }

  for (short row = 0; row < 5; row++) {
    for (short col = 0; col < 5; col++) {
      findSixDigits(row, col, string(1, arr[row][col]));
    }
  }

  cout << sixDigits.size() << endl;
  return 0;
}