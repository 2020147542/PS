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

// 결국 모든 경우를 다 돌아야함
// dp = 현재 날짜에 얻을 수 있는 수익들
long solution()
{
    vector<vector<long>> dp(N + 1, vector<long>());   // dp는 각 벡터가 빈 상태로 초기화
    vector<vector<int>> choice(N + 1, vector<int>()); // choice도 각 벡터가 빈 상태로 초기화

    // dp[1]과 choice[1]에만 초기값 할당
    dp[0].push_back(0);
    choice[0].push_back(0);

    for (int today = 1; today <= N; today++) {
        for (int j = 0; j < dp[today - 1].size(); j++)
        {
            int lastchoice = choice[today - 1][j];

            // 오늘 추가
            if (today >= lastchoice + times[lastchoice])
            {
                int cTime = today + times[today];
                int cPay = dp[today-1][j] + pays[today];

                if (cTime <= N + 1 && find(dp[today].begin(), dp[today].end(), cPay) == dp[today].end())
                {
                    choice[today].push_back(today);
                    dp[today].push_back(cPay);
                }
            }

            // 오늘 추가 안 함
            int tomorrow = today + 1;
            int tomorrowPay = dp[today - 1][j];

            if (tomorrow <= N + 1 && find(dp[today].begin(), dp[today].end(), tomorrowPay) == dp[today].end())
            {
                choice[today].push_back(lastchoice);
                dp[today].push_back(tomorrowPay);
            }
        }
    }

    return *max_element(dp[N].begin(), dp[N].end());
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

    // 최대 합에 적절한 limit이 없어서 주어진 값으로 구한 Limit 사용시 메모리 오버 남.
    cout << solution() << endl;

    return 0;
}