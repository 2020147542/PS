#include <iostream>
using namespace std;

int n, k;
int arr[100];
int cache[10001];

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }

  cache[0] = 1;  // 동전 값과 현재 값이 같을 때 무조건 1씩 더해짐
  for (int i = 0; i < n; i++) {
    for (int j = 1; j <= k; j++) {
      if (j < arr[i]) continue;  // arr[i]보다 큰 금액에 대해서만 확인

      cache[j] += cache[j - arr[i]];
    }
  }

  cout << cache[k] << "\n";

  return 0;
}