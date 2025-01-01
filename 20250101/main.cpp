/*

문제: 2579번 계단 오르기

- 제한시간 1초, 메모리 제한: 128MB
- 계단 아래 시작점부터 계단 꼭대기에 위치한 도착점까지 가는 게임
- 각각의 계단에는 일정한 점수가 쓰여 있는데, 계단을 밟으면 그 계단에 쓰여 있는 점수를 얻게 됨
- 계단 오르는 규칙
    1) 한 번에 하나씩 or 두 계단씩 오를 수 있음
    2) 연속된 세 계단을 모두 밟아서는 안된다 (단, 시작점은 계단에 포함되지 않음)
    3) 마지막 도착 계단은 무조건 밟아야 함
- 각 계단에 쓰여있는 점수가 주어질 때, 이 게임에서 얻을 수 있는 총 점수의 최댓값을 구헤라

- 입력: 계단의 개수(300이하 자연수), 계단에 쓰여있는 점수(10000이하 자연수)
- 출력: 계단 오르기 게임에서 얻을 수 있는 총 점수의 최댓값 출력

*/

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N;
vector<int> stairs;

/*
    ** 점화식 찾기
    dp = 현재 계단을 반드시 밟으면서 얻을 수 있는 최대 스코어
    최대 점수를 가지면서, 1번 계단을 반드시 밟는 경우 : 1
    최대 점수를 가지면서, 2번 계단을 반드시 밟는 경우 : 1-2
    최대 점수를 가지면서, 3번 계단을 반드시 밟는 경우 : 1-3, 2-3
    최대 점수를 가지면서, 4번 계단을 반드시 밟는 경우 : 1-2-4, 1-3-4
    최대 점수를 가지면서, 5번 계단을 반드시 밟는 경우 : 1-2-4-5, 1-3-5, 2-3-5

    dp[1] = stair[1]
    dp[2] = stair[1] + stair[2]
    dp[3] = max(stair[1] + stair[3], stair[2] + stair[3])

    dp[4] = max(dp[2] + stair[4], dp[1] + stair[3] + stair[4])
    dp[5] = max(dp[3] + stair[5], dp[2] + stair[4] + stair[5])

    정리하면 dp[N] = max(dp[N-2] + stair[N], dp[N-3] + stair[N-1] + stair[N])
*/
int findMax(){
    vector<int> dp(N + 1, 0);
    dp[1] = stairs[1];
    dp[2] = stairs[1] + stairs[2];
    dp[3] = max(stairs[1] + stairs[3], stairs[2] + stairs[3]);

    for (int i = 4; i <= N; i++){
        dp[i] = max((dp[i - 2] + stairs[i]), (dp[i - 3] + stairs[i - 1] + stairs[i]));
    }

    return dp[N];
}

int main()
{
    // 1. 입력받기
    cin >> N;

    stairs.resize(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        cin >> stairs[i];
    }

    // 2. 최대값 찾기
    cout << findMax() << endl;

    return 0;
}