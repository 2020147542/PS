#include <algorithm>
#include <iostream>
using namespace std;

int n, ans;
int arr[1001];
int cache[1001];  // 1부터 i까지 부분 증가 수열의 합의 최대 단, i를 반드시
                  // 포함함

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
    cache[i] = arr[i];
  }

  ans = arr[1];
  for (int i = 2; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (arr[j] < arr[i]) {
        cache[i] = max(cache[i], cache[j] + arr[i]);
      }
    }

    ans = max(ans, cache[i]);
  }

  cout << ans << "\n";

  return 0;
}