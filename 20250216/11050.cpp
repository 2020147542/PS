#include <cstdio>
#include <iostream>
using namespace std;

int n, k;
int cache[11][11];

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cache[i][0] = 1;
    cache[i][i] = 1;
  }

  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= k; j++) {
      if (i < j) break;
      cache[i][j] = cache[i - 1][j - 1] + cache[i - 1][j];
    }
  }
  cout << cache[n][k] << endl;

  return 0;
}