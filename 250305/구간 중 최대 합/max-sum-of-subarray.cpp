#include <iostream>
#include <algorithm>
using namespace std;

int n, k, ans;
int arr[111];

int main() {
    // Please write your code here.
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // 모든 경우에
    for(int i = 0; i < n - k + 1; i++){
        int sum = 0;
        
        // 할걸 한다
        for(int j = i; j < i + k; j++){
            sum += arr[j];
        }

        ans = max(ans, sum);
    }


    cout << ans;
    
    return 0;
}