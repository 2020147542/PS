#include <iostream>
#include <climits>
using namespace std;

int n, k, b;
int min_val = INT_MAX;
bool arr[111111];

int main() {
    // Please write your code here.
    cin >> n >> k >> b;

    for(int i = 0; i < b; i++){
        int idx;
        cin >> idx;
        arr[idx] = true;
    }

    for(int i = 1; i <= n - k; i++){
        int cnt = 0; 
        for(int j = 0; j < k; j++){
            if(arr[i+j]) cnt++;
        }
        min_val = min(min_val, cnt);
    }

    cout << min_val;

    return 0;
}