#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pir;

int n, ans;
pir lines[20];
vector<pir> arr;

void choose(int idx){
    if(idx >= n){
        sort(arr.begin(), arr.end());

        for(int i = 1; i < arr.size(); i++){
            if(arr[i-1].second >= arr[i].first) return;
        }

        ans = max(ans, (int)arr.size());
        return;
    }

    // 현재 것을 선택하는가
    arr.push_back(lines[idx]);
    choose(idx + 1);

    // 선택 안하는가
    arr.pop_back();
    choose(idx + 1);
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> lines[i].first >> lines[i].second;
    }

    choose(0);
    cout << ans;

    return 0;
}