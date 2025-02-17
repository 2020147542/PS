#include <iostream>
#include <vector>
using namespace std;

int n;
const int MOD = 1000000000;
vector<vector<int> > cache;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  cache.resize(n, vector<int>(10, 0));

  for (int i = 1; i < 10; i++) {
    cache[0][i] = 1;
  }

  for (int j = 1; j < n; j++) {
    for (int i = 0; i < 10; i++) {
      int below = i == 0 ? 0 : cache[j - 1][i - 1];
      int above = i == 9 ? 0 : cache[j - 1][i + 1];

      cache[j][i] = (below + above) % MOD;
    }
  }

  int sum = 0;
  for (int i = 0; i < 10; i++) {
    sum = (sum + cache[n - 1][i]) % MOD;
  }

  cout << sum % MOD << "\n";

  return 0;
}