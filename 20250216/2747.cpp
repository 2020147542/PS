#include <iostream>
using namespace std;

int n;  // 최대 45
int fibo[46];

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  fibo[0] = 0;
  fibo[1] = 1;

  for (int i = 2; i <= n; i++) {
    fibo[i] = fibo[i - 1] + fibo[i - 2];
  }

  cout << fibo[n] << "\n";
  return 0;
}