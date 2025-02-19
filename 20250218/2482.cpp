#include <iostream>
using namespace std;

int n, k, cache[1001][1001];
const int MOD = 1000000003;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cache[i][1] = i;
  }

  for (int i = 4; i <= n; i++) {
    for (int j = 2; j <= i / 2; j++) {
      cache[i][j] = (cache[i - 2][j - 1] + cache[i - 1][j]) % MOD;
    }
  }

  cout << cache[n][k] << "\n";

  return 0;
}
