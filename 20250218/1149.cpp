#include <algorithm>
#include <iostream>
using namespace std;

int n;
int arr[1000][3];
int cache[1000][3];  // 각 집이 r, g, b를 선택할 때, 지금까지 든 전체 최소 비용

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }

  cache[0][0] = arr[0][0];
  cache[0][1] = arr[0][1];
  cache[0][2] = arr[0][2];

  for (int i = 1; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      cache[i][j] =
          min(cache[i - 1][(j + 1) % 3], cache[i - 1][(j + 2) % 3]) + arr[i][j];
    }
  }

  cout << min({cache[n - 1][0], cache[n - 1][1], cache[n - 1][2]}) << "\n";
  return 0;
}