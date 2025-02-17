#include <iostream>
#include <map>
#include <vector>
using namespace std;

bool isTree(map<int, vector<int>> &tree) {
  bool res = false;

  return res;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int u, v, k = 0;
  map<int, vector<int>> tree;

  while (true) {
    cin >> u >> v;

    if (u == -1 && v == -1) {
      break;
    }

    if (u == 0 && v == 0) {
      k++;
      if (isTree(tree)) {
        cout << "Case" << k << "is a tree.\n";
      } else {
        cout << "Case" << k << "is not a tree.\n";
      }

      tree.clear();
    } else {
      tree[u].push_back(v);
    }
  }

  return 0;
}