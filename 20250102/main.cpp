/*

문제: 11726번 2Xn 타일링

- 2Xn 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수를 구하는 프로그램을 작성해라

- 입력: n이 주어짐(1~1000)
- 출력: 2Xn 크기의 직사각형을 채우는 방법의 수를 10,007로 나눈 나머지 출력

*/

#include <iostream>
#include <vector>

using namespace std;

int n;

int main() {

    // 1. 입력 받기
    cin >> n;

    /*
        2. 직사각형 채우기 점화식

        2x1을 채우는 방법 = 1가지
        2x2를 채우는 방법 = 2가지
        2x3을 채우는 방법 = 3가지 
        2x4를 채우는 방법 = 5가지
        2x5를 채우는 방법 = 8가지
        2x6을 채우는 방법 = 13가지
        ...
        2x9를 채우는 방법 = 55가지 ()

        dp[n] = dp[n-1] + dp[n-2]
    */

    vector<long> dp(n+1, 0);
    dp[1] = 1;
    dp[2] = 2;

    for (int i = 3; i <= n; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % 10007;
    }

    cout << dp[n] << endl;

    return 0;
}