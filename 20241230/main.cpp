/*

문제: 2748번 피보나치 수2

- 피보나치 수는 0과 1로 시작 (0번째 피보나치 = 0, 1번째 피보나치 = 1)
- 즉, fn = f(n-1) + f(n-2), n >= 2
- n = 17이면 0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597
- n이 주어졌을 때, n번째 피보나치 수를 구하는 프로그램을 작성하시오

- 입력: n은 90보다 작거나 같은 수
- 출력: n번째 피보나치 수

*/
#include <iostream>
#include <vector>

using namespace std;

long fibo(int n, vector<long> &dp){

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int N;
    cin >> N;

    vector<long> dp(N + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    cout << fibo(N, dp) << endl;
    return 0;
}