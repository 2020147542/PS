#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int T, n;
int x[1001];
int cache[1001][1001];

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  freopen("input.txt", "r", stdin);
  cin >> T;
  for (int t = 0; t < T; t++) {
    memset(cache, 0, sizeof(cache));
    cin >> n;

    for (int i = 1; i <= n; i++) {
      cin >> x[i];
    }

    int ans = -10000000;
    for (int i = 1; i <= n; i++) {
      for (int j = i; j <= n; j++) {
        if (i == j) {
          cache[i][j] = x[j];
        } else {
          cache[i][j] = cache[i][j - 1] + x[j];
        }

        ans = max(ans, cache[i][j]);
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
