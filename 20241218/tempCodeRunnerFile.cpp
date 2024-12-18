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

vector<int> days(1);
vector<int> pays(1);

int totalPay = 0;
int N;

// 1일 선택 (3일간) = 비교군 2, 3일
// 1일에 벌 수 있는 돈 = 10, 포기하는 돈 = 30(일 못하는 2일 + 3일) => 10 - 30 = -20
// 2일에 벌 수 있는 돈 = 20, 포기하는 돈 = 295(일 못하는 1일 + 3 ~ 6일) => 20 - 95 = -75
// 3일에 벌 수 있는 돈 = 10, 포기하는 돈 = 30(일 못하는 1일 + 2일) => 10 - 30 = -20
// -> 결론은 1과 3중에 가장 빠른 1일 선택
int beRich(int startDate)
{
    int lastDays = startDate + days[startDate];
    int maxIdx = 0;           // 버는 돈이 최대인 날
    int maxProfit = -1000000; // 최소 실패가 언제인지 비교하기 위한 변수
    int sumUntilI = 0;        // i번째 일을 선택함으로써, 벌지못하는 이전 날의 돈 합산

    for (int i = startDate; i < lastDays && i <= N; i++)
    {
        if (i + days[i] - 1 > N)
        {
            continue;
        }

        // 이 선택지를 고르므로써, 이후에 벌지 못하는 돈 합산
        int lossWithChoice = 0;
        for (int j = i + 1; j < i + days[i]; j++)
        {
            lossWithChoice += pays[j];
        }

        // 현재 선택지를 골라서 버는 돈 - (다른 선택지를 못 골라서 벌지 못하는 돈 + 이후에 벌지 못하는 돈)
        int currentProfit = pays[i] - (sumUntilI + lossWithChoice);

        if (maxProfit < currentProfit)
        {
            maxProfit = currentProfit;
            maxIdx = i;
        }

        // 다른 선택지를 포기하면서 벌지 못하는 돈 합산
        sumUntilI += pays[i];
    }

    // 최종 선택한 선택지 비용 합산
    totalPay += pays[maxIdx];

    // 최종 선택된 '일' + 기간 - 1로 넘겨줌
    return maxIdx == 0 ? startDate : (maxIdx + days[maxIdx] - 1);
}

int main()
{
    // 1. 입력 받기
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        int day, pay;
        cin >> day >> pay;

        if (i + day - 1 > N)
        {
            pay = 0;
        }

        days.push_back(day);
        pays.push_back(pay);
    }

    // 2. 백준이가 얻는 최대 수익 찾기
    for (int i = 1; i < N + 1; i++)
    {
        // 다음으로 고려할 상담 날짜로 이동
        i = beRich(i);
    }

    // 3. 출력
    cout << totalPay << endl;

    return 0;
}