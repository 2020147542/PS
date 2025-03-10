#include <iostream>
#include <climits>
using namespace std;

int n, k, max_idx = INT_MIN;
int bombs[111];

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> bombs[i];
    }

    for(int i = 0; i < n; i++){
        for(int j = i - k; j < i; j++){
            if(j < 0) continue;
            if(bombs[i] == bombs[j]){
                max_idx = max(max_idx, bombs[j]);
            }
        }
    }

    if(max_idx == INT_MAX){
        cout << -1;
    } else{
        cout << max_idx;
    }

    return 0;
}