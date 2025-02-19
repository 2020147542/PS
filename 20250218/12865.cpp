#include <algorithm>
#include <iostream>
using namespace std;

int n, k;
int w[101];
int v[101];
int cache[100001][101];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 무게 k를 맞춰서, 얻을 수 있는 최대 가치는?
  cin >> n >> k;

  for (int i = 1; i <= n; i++) {
    cin >> w[i] >> v[i];
  }

  for (int i = 1; i <= n; i++) {
    for (int t = 1; t <= k; t++) {
      if (t < w[i]) {
        cache[t][i] = cache[t][i - 1];
      } else {
        cache[t][i] = max(cache[t - w[i]][i - 1] + v[i], cache[t][i - 1]);
      }
    }
  }

  cout << cache[k][n] << "\n";

  return 0;
}