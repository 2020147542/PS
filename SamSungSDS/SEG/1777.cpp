#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;

int N, H, tree_size, half_size;
vector<int> inv;  // Inversion sequence
vector<int> SEG;  // 해당 구간에 존재하는 빈 자리의 수를 나타냄
vector<int> ans;

// k번째 빈자리는 어디인가?
int query(int k, int cur) {
  if (SEG[cur] == 0) return 0;              // 값이 0인 경우
  if (cur > tree_size / 2 - 1) return cur;  // leaf 노드이면서 값이 있는 경우

  int a = 0, b = 0;
  if (SEG[2 * cur] >= k) {
    a = query(k, cur * 2);
  } else {
    b = query(k - SEG[2 * cur], cur * 2 + 1);
  }

  return a + b;
}

void update(int idx, int num) {
  SEG[idx] = num;

  while (idx) {
    idx /= 2;
    SEG[idx] = SEG[idx * 2] + SEG[idx * 2 + 1];
  }
}

void init() {
  for (int i = half_size - 1; i >= 1; i--) {
    SEG[i] = SEG[i * 2] + SEG[i * 2 + 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  cin >> N;
  inv.resize(N, 0);
  ans.resize(N + 1, 0);

  H = (int)ceil(log2(N));
  half_size = 1 << H;
  tree_size = half_size * 2;
  SEG.resize(tree_size + 1, 0);

  for (int i = 0; i < N; i++) {
    cin >> inv[i];
    SEG[tree_size / 2 + i] = 1;
  }

  init();

  // 가장 큰 수부터 거꾸로 넣기
  for (int i = N - 1; i >= 0; i--) {
    int k = query(SEG[1] - inv[i], 1);
    update(k, 0);
    ans[k - half_size] = i + 1;
  }

  for (int i = 0; i < N; i++) {
    cout << ans[i] << " ";
  }
  cout << '\n';

  return 0;
}