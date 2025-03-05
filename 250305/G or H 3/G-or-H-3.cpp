#include <iostream>
using namespace std;

int n, k;
char arr[11111];
int ans, max_pos = 10000;

int main() {
    // Please write your code here.
    // 모든 경우에
    // 모든 k 크기의 구간에 대해서
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int pos;
        cin >> pos >> arr[pos];
    }

    for(int i = 1; i <= max_pos - k; i++){
        int cnt = 0;
        for(int j = i; j <= i + k; j++){
            if(arr[j] == 'H') cnt += 2;
            else if(arr[j] == 'G') cnt++;
        }

        // 할거 한다.
        // 최대 점수를 구한다.
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}