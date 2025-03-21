#include <iostream>
using namespace std;

int n, k, cnt;
int arr[1111];
int sum[1111];

int main() {
    // Please write your code here.
    cin >> n >> k;

    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        sum[i] = sum[i-1] + arr[i];
    }

    for(int i = 1; i <= n; i++){
        for(int j = i - 1; j >= 0; j--){
            if(sum[i] - sum[j] == k) cnt++;
        }
    }

    cout << cnt;

    return 0;
}