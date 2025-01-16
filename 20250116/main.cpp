#include <algorithm>
#include <iostream>
#include <map>

using namespace std;

int N, R;

map<int, pair<int, int>> frames;

void whereToPut(int who, int seq) {
  // 0. 이미 후보에 있는지 확인
  if (frames.find(who) != frames.end()) {
    frames[who].first++;
    return;
  }

  // 1. 빈 공간이 있으면 그 안으로 들어감
  if (frames.size() < N) {
    frames[who] = {1, seq};
    return;
  }

  // 2. 추천 수 + 추천 일자 순으로 정렬
  vector<pair<int, pair<int, int>>> frameCopy(frames.begin(), frames.end());
  sort(frameCopy.begin(), frameCopy.end(),
       [](const pair<int, pair<int, int>>& a,
          const pair<int, pair<int, int>>& b) {
         if (a.second.first == b.second.first)
           return a.second.second < b.second.second;
         return a.second.first < b.second.first;
       });

  frames.erase(frameCopy[0].first);
  frames[who] = {1, seq};
}

int main() {
  cin >> N >> R;

  int who;
  for (int i = 0; i < R; i++) {
    cin >> who;

    whereToPut(who, i);
  }

  for (const auto& p : frames) {
    cout << p.first << " ";
  }
  cout << endl;

  return 0;
}