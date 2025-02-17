#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int N, H, tree_size, half_size, pi;
vector<int> tree;

int query(int k, int cur_idx) {
  if (tree[cur_idx] == 0) return 0;
  if (cur_idx >= half_size) return cur_idx;

  int l = 0, r = 0;
  if (tree[cur_idx * 2] >= k) {
    l = query(k, cur_idx * 2);
  } else {
    r = query(k - tree[cur_idx * 2], cur_idx * 2 + 1);
  }

  return l + r;
}

void update(int idx, int value) {
  tree[idx] = value;
  while (idx) {
    idx /= 2;
    tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
  }
}

void init() {
  for (int i = half_size - 1; i >= 1; i--) {
    tree[i] = tree[i * 2] + tree[i * 2 + 1];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("input.txt", "r", stdin);
  cin >> N;

  H = (int)ceil(log2(N));
  half_size = 1 << H;
  tree_size = 2 * half_size;
  tree.resize(tree_size + 1,
              0);  // 1부터 시작, 각 구간에 해당하는 정수의 총 개수

  for (int i = 0; i < N; i++) {
    cin >> tree[half_size + i];
  }

  init();

  for (int i = 0; i < N; i++) {
    cin >> pi;

    int pos = query(pi, 1);
    update(pos, 0);
    cout << pos - half_size + 1 << " ";
  }
  cout << "\n";

  return 0;
}