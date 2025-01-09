#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int k;
vector<char> signs;
vector<string> answers;

bool isSame(string &kNumList, string numList) {
  string thisNumList = numList.substr(0, k + 1);

  if (kNumList == thisNumList) return true;
  kNumList = thisNumList;

  return false;
}

void solution() {
  string numList = "0123456789";
  string kNumList = "";

  do {
    if (isSame(kNumList, numList)) continue;

    for (int i = 0; i < k; i++) {
      short before = numList[i] - '0';
      short after = numList[i + 1] - '0';

      if (signs[i] == '<' && before >= after) break;
      if (signs[i] == '>' && before <= after) break;

      if (i == k - 1) answers.push_back(kNumList);
    }

  } while (next_permutation(numList.begin(), numList.end()));
}

int main() {
  cin >> k;

  signs.resize(k);
  for (int i = 0; i < k; i++) {
    cin >> signs[i];
  }

  solution();

  cout << *max_element(answers.begin(), answers.end()) << endl;
  cout << *min_element(answers.begin(), answers.end()) << endl;

  return 0;
}