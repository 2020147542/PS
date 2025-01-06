#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool compare(int a, int b) { return a > b; }

vector<int> solution(vector<int> lst) {
  sort(lst.begin(), lst.end(), compare);
  lst.erase(unique(lst.begin(), lst.end()), lst.end());

  return lst;
}

int main() {
  vector<int> arr = {4, 2, 2, 1, 3, 4};

  vector<int> result = solution(arr);

  for (int ele : result) {
    cout << ele << " ";
  }
  cout << endl;

  return 0;
}