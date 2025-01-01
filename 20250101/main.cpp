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

using namespace std;

int N;
vector<long> stairs;

void findMax(vector<pair<long, long>> &dp)
{
    int maxIdx = 0;
    for (int i = 3; i <= N; i++)
    {
        if (dp[i - 1].second != i - 2 && dp[i - 1].first > dp[i - 2].first)
            maxIdx = i - 1;
        else
            maxIdx = i - 2;

        dp[i].first = dp[maxIdx].first + stairs[i];
        dp[i].second = maxIdx;
    }
}

int main()
{

    cin >> N;

    stairs.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> stairs[i];
    }

    // 현재 계단까지의 포인트 최댓값 구하기
    vector<pair<long, long>> dp(N + 1, {0, 0});
    dp[1] = {stairs[1], 0};
    dp[2] = {stairs[1] + stairs[2], 1};

    findMax(dp);

    cout << dp[N].first << endl;

    return 0;
}