#include <iostream>
#include <climits>
using namespace std;

int n, k, max_cnt = INT_MIN;
int min_val = INT_MAX, max_val = INT_MIN;
int arr[111];

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> arr[i];

        min_val = min(min_val, arr[i]);
        max_val = max(max_val, arr[i]);
    }

    for(int k = min_val; k <= max_val; k++){
        int cnt = 0;

        for(int i = 0; i < n; i++){
            int diff = k - arr[i];

            for(int j = i + 1; j < n; j++){
                if(arr[j] - k == diff) cnt++;
            }
        }

        max_cnt = max(max_cnt, cnt);
    }

    cout << max_cnt;
    return 0;
}