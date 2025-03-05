#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int n, ans = INT_MAX;
int a[111];

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    // 모든 경우에 
    for(int i = 1; i <= n; i++){
        int cnt = 0;
        
        // 할거 한다.
        for(int j = 1; j <= n; j++){
            cnt = cnt + abs(i - j) * a[j];
        }

        ans = min(ans, cnt);
    }


    cout << ans;
    return 0;
}