#include <iostream>
using namespace std;

int n;
const int MOD = 10007;
int tile[1001];

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  tile[0] = 1;
  tile[1] = 1;

  for (int i = 2; i <= n; i++) {
    tile[i] = (tile[i - 1] + tile[i - 2] * 2) % MOD;
  }

  cout << tile[n] << "\n";
  return 0;
}