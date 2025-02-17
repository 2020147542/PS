#include <algorithm>
// #include <cstdio>
#include <iostream>
using namespace std;

int T, n;
int sticker[2][100001];
int cache[2][100001];

// 1초
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 뗄 수 없다.
  // 점수의 합이 최대가 되게 스티커를 떼어내려고 한다
  // 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합 구하기
  // freopen("input.txt", "r", stdin);
  cin >> T;
  for (int t = 0; t < T; t++) {
    cin >> n;

    for (int i = 0; i < 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> sticker[i][j];
      }
    }

    cache[0][1] = sticker[0][1];
    cache[1][1] = sticker[1][1];
    for (int i = 0; i < 2; i++) {
      for (int j = 2; j <= n; j++) {
        cache[1][j] = max(cache[0][j - 1], cache[0][j - 2]) + sticker[1][j];
        cache[0][j] = max(cache[1][j - 1], cache[1][j - 2]) + sticker[0][j];
      }
    }

    cout << max(cache[0][n], cache[1][n]) << "\n";
  }

  return 0;
}
