#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int N, K;
int max_people = 0;
vector<pair<char, bool>> hamburger;

bool canEat(int pos) {
  if (hamburger[pos].first == 'P') return false;
  if (hamburger[pos].second) return false;

  hamburger[pos].second = true;
  max_people += 1;
  return true;
}

int main() {
  cin >> N >> K;

  for (int i = 0; i < N; i++) {
    char thing;
    cin >> thing;

    hamburger.push_back({thing, false});
  }

  for (int i = 0; i < N; i++) {
    if (hamburger[i].first == 'H') continue;

    for (int pos = i - K; pos <= i + K; pos++) {
      if (pos < 0 || pos >= N || pos == i) continue;
      if (canEat(pos)) break;
    }
  }

  cout << max_people << endl;
  return 0;
}