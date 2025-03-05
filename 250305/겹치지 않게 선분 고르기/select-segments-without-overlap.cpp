#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef pair<int, int> pir;

int n, ans;
int visited[1111];
pir lines[20];
vector<pir> arr;

void choose(int idx){
    if(idx >= n){
        memset(visited, 0, sizeof(visited));
        
        for(int i = 0; i < arr.size(); i++){
            for(int j = arr[i].first; j <= arr[i].second; j++){
                if(visited[j]) return;
                visited[j]++;
            }
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