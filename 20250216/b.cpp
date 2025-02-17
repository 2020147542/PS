#include <algorithm>
#include <iostream>
using namespace std;

int N;
int cache[101];  // i번째 줄까지 얻을 수 있는 최대 식량 값
int arr[101];

int main() {
  cin >> N;

  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }

  cache[1] = arr[1];
  cache[2] = max(arr[1], arr[2]);
  for (int i = 3; i <= N; i++) {
    // 2가지 경우가 존재
    // 현재 i번째 방을 털것인가 말것인가
    // 안털경우와 털 경우 중 최대값 고르기
    cache[i] = max(cache[i - 2] + arr[i], cache[i - 1]);
  }

  cout << cache[N] << endl;

  return 0;
}