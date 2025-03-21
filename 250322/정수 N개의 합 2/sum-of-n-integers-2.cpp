#include <iostream>
#include <climits>
using namespace std;

int n, k;
int max_val = INT_MIN;
int arr[100010];
int sum[100010];

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i = 1; i <= n - k; i++){
        max_val = max(max_val, sum[i+k] - sum[i]);
    }

    cout << max_val;
    return 0;
}