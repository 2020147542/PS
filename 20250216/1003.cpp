// #include <cstdio>
#include <iostream>
using namespace std;

int T, N;
int fibo[41][2];

// 0.25초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  fibo[0][0] = 1;
  fibo[1][1] = 1;
  fibo[2][0] = 1;
  fibo[2][1] = 1;
  for (int i = 3; i <= 40; i++) {
    fibo[i][0] = fibo[i - 1][0] + fibo[i - 2][0];
    fibo[i][1] = fibo[i - 1][1] + fibo[i - 2][1];
  }

  // freopen("input.txt", "r", stdin);
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> N;
    cout << fibo[N][0] << " " << fibo[N][1] << "\n";
  }

  return 0;
}