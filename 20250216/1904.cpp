// #include <cstdio>
#include <iostream>
using namespace std;

int n;
const int MOD = 15746;
int bin[1000001];

// 0.75초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // freopen("input.txt", "r", stdin);
  cin >> n;
  bin[1] = 1;
  bin[2] = 2;
  for (int i = 3; i <= n; i++) {
    bin[i] = (bin[i - 2] + bin[i - 1]) % MOD;
  }

  cout << bin[n] << "\n";
  return 0;
}