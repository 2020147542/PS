#include <iostream>
#include <climits>
using namespace std;

int n, k;
int busket[111];
int ans = INT_MIN;

int main() {
    // Please write your code here.
    // 모든 경우에 대하여
    // 모든 구간에 대하여
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        busket[b] += a; // 같은 위치 여러 바구니 가능
    }

    for(int c = 0; c < 100; c++){
        int sum = 0;
        for(int i = c - k; i <= c + k; i++){
            // 할걸 하자
            // 최대가 되는 사탕의 수를 구하자  
            sum += busket[i];
        }

        ans = max(ans, sum);
    }

    cout << ans;

    return 0;
}