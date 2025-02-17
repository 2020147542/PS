#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int N, K;
ll sum;
const int MAX_NUM = 65537;
const int H = (int)ceil(log2(MAX_NUM));
const int FLOOR = 1 << H;
vector<int> arr;
vector<int> SEG;

// seg트리를 이분 탐색하면서 mid번째 수를 구해라 - log(2*FLOOR)
int query(int mid, int cur) {
  if (SEG[cur] == 0) return 0;
  if (cur >= FLOOR && SEG[cur] > 0) return cur - FLOOR;

  int a = 0, b = 0;
  if (mid <= SEG[cur * 2]) {
    a = query(mid, 2 * cur);
  } else {
    b = query(mid - SEG[cur * 2], 2 * cur + 1);
  }

  return a + b;
}

void init() {
  for (int i = FLOOR - 1; i >= 1; i--) {
    SEG[i] = SEG[i * 2] + SEG[i * 2 + 1];
  }
}

void update(int idx, int num) {
  SEG[idx] += num;

  while (idx) {
    idx /= 2;
    SEG[idx] = SEG[idx * 2] + SEG[idx * 2 + 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  cin >> N >> K;
  arr.resize(N);             // 입력받은 배열 저장
  SEG.resize(2 * FLOOR, 0);  // 0 ~ 65536까지 수가 나온 횟수 저장

  for (int i = 0; i < N; i++) {
    cin >> arr[i];

    if (i < K) {
      SEG[FLOOR + arr[i]]++;
    }
  }

  init();

  // N - K + 1 수의 구간 만큼, 각 구간에서 'k+1/2'번째 수가 뭔지 쿼리 진행
  for (int i = 0; i < N - K + 1; i++) {
    int mid = (K + 1) / 2;  // 중앙값
    sum += query(mid, 1);

    int left = arr[i];       // 빠질 수
    int right = arr[i + K];  // 들어갈 수
    update(FLOOR + left, -1);
    update(FLOOR + right, 1);
  }

  cout << sum << '\n';

  return 0;
}