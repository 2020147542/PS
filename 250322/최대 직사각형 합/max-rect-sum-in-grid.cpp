#include <iostream>
#include <climits>
using namespace std;

int n;
int ans = INT_MIN;
int grid[310][310];
int sum[310][310];
int dp[310];

int getmaxArea(int h1, int h2){

    int res = INT_MIN;

    for(int i = 1; i <= n; i++){
        // 세로 구간 h1~h2인 열 한 줄짜리 직사각형
        int value = sum[h2][i] - sum[h1 - 1][i] - sum[h2][i-1] + sum[h1-1][i-1];
        dp[i] = max(value, dp[i-1] + value); // 새로 시작할 지 or 이어서 갈지
        res = max(res, dp[i]);
    }

    return res;
}

int main() {
    // Please write your code here.
    cin >> n;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> grid[i][j];
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + grid[i][j];
        }
    }

    for(int h1 = 1; h1 <= n; h1++){
        for(int h2 = h1; h2 <= n; h2++){
            ans = max(ans, getmaxArea(h1, h2));
        }
    }

    cout << ans;

    return 0;
}