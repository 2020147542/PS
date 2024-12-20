/*

문제: 14501번 퇴사

- 백준이는 남은 N일 동안 최대한 많은 상담을 진행하려고 함
- 하루에 하나씩 서로 다른 사람의 상담 진행
- 각각의 상담을 완료하는 데 걸리는 기간 = Ti일, 각 상담 비용 = Pi
- 상담을 하는데 필요한 시간이 1일 보다 클 수 있기에, 모든 상담은 불가능하다
- ex) 1일에 잡힌 3일 걸리는 상담을 진행하면, 2일/3일은 상담 진행 불가
- N+1일째는 회사에 존재하지 않으므로 상담 완료일이 N일 이후라면 상담 진행 불가
- 상담을 적절히 했을 때, 백준이가 얻을 수 있는 최대 수익은 ?

- 입력: 1 <= N <= 15, 둘째 줄부터 Ti(1~5), Pi(1~1000)가 공백으로 주어짐
- 출력: 백준이가 얻는 최대 이익

** 앞에서 순서대로 한다해서 항상 최대 이익은 아님, 돈 많이 주는 걸 하나만 해도 이득

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> days;
vector<int> pays;

int N;

// 모든 경우의 수 모두 돌기
// 각 날의 일을 하는 경우 vs 하지 않고, 다른 일을 하는 경우를 모두 고려해서 둘 중 큰 값 저장
// day_now: 오늘
// pay_now: 오늘까지 번 돈
int max_payment(int day_now, int pay_now)
{
    if (day_now == N)
    {
        return pay_now; // 마지막 날 - 하루만에 끝낼 수 있는 경우
    }
    else if (day_now > N)
    {
        return -1; // 일을 할 수 없는 경우
    }
    int day = days[day_now];
    int pay = pays[day_now];

    int a = max_payment(day_now + day, pay_now + pay); // 현재 일을 선택한 경우
    int b = max_payment(day_now + 1, pay_now);         // 다른 일을 하는 경우

    return max(a, b);
}

int main()
{
    // 1. 입력 받기
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int day, pay;
        cin >> day >> pay;

        days.push_back(day);
        pays.push_back(pay);
    }

    // 2. 백준이가 얻는 최대 수익 찾기
    // 재귀로 접근
    cout << max_payment(0, 0) << endl;

    return 0;
}
