/*

문제: 15486번 퇴사2

- 제한시간: 2초, 메모리: 512MB
- N+1일 째 되는날 퇴사를 하기 위해, 남은 N일 동안 최대한 많은 상담을 하고자 함
- 하루에 하나씩 서로 다른 사람의 상담을 잡아놓음
- 상담을 완료하는데 걸리는 기간 Ti, 상담했을 때 받을 수 있는 금액 Pi
- 상담을 하는데 필요한 기간은 1일 이상이므로, 모든 상담을 할 수는 없음
- 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익은?

- 입력: N (1 ≤ N ≤ 1,500,000), N개의 줄에 Ti(1~50)와 Pi(1~1000)가 날짜 순서대로 주어짐
- 출력: 백준이가 얻을 수 있는 최대 이익

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> times;
vector<int> pays;

// dp = 현재 날짜에 얻을 수 있는 최대 수익
long solution()
{
    vector<long> dp(N + 2, 0);
    long maximum = 0;

    for (int day_now = 1; day_now <= N; day_now++)
    {
        // 오늘 포함한 경우 -> 오늘 값을 포함한 값을 넘겨줘야함
        int day_next = day_now + times[day_now];
        long pay_next = 0;

        if (day_next <= N + 1) {
            pay_next = dp[day_now] + pays[day_now];
            maximum = max(maximum, pay_next);
            dp[day_next] = max(pay_next, dp[day_next]);
        }

        // 오늘 아무것도 안한 경우 -> 오늘 값이 포함되지 않은 값을 넘겨줘야함
        dp[day_now + 1] = max(dp[day_now], dp[day_now + 1]);

        // 오늘 최대값 저장
        dp[day_now] = maximum;
    }

    return dp[N];
}

int main()
{

    cin >> N;

    times.resize(N + 1, 1);
    pays.resize(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> times[i] >> pays[i];
    }

    cout << solution() << endl;

    return 0;
}