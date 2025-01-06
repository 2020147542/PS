#include <iostream>

using namespace std;

int H, W, N;
int input[100][2];
int w_max = 0;

bool isPossible(int i, int j) {
  for (int s1 = 0; s1 < 2; s1++) {
    for (int s2 = 0; s2 < 2; s2++) {
      int h1 = input[i][s1];
      int h2 = input[j][s2];
      int w1 = input[i][1 - s1];
      int w2 = input[j][1 - s2];

      if (h1 > H || h2 > H) continue;
      if (w1 > W || w2 > W) continue;

      int rH = H - h1;
      int rW = W - w1;

      if (h2 <= rH || w2 <= rW) return true;
    }
  }

  return false;
}

void findMax() {
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      int sticker1 = input[i][0] * input[i][1];
      int sticker2 = input[j][0] * input[j][1];

      if (sticker1 > H * W || sticker2 > H * W || sticker1 + sticker2 > H * W)
        continue;

      if (isPossible(i, j)) {
        w_max = max(w_max, sticker1 + sticker2);
      }
    }
  }

  cout << w_max << endl;
}

int main() {
  cin >> H >> W >> N;

  for (int i = 0; i < N; i++) {
    cin >> input[i][0] >> input[i][1];
  }

  findMax();

  return 0;
}