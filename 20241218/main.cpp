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
#include <algorithm>

using namespace std;

vector<int> days(1);
vector<int> pays(1);
vector<int> bestProfit(1);

int N;
int chosen = 0;

// 주어진 날의 최대 수익 구하기
void findBestProfit(int today)
{
    const int maxDay = days[today] + today;
    cout << "today: " << today << endl;
    cout << "maxDay: " << maxDay << endl;
    if (maxDay - 1 <= N)
    {

        cout << "bestProfit[today]: " << bestProfit[today] << endl;
        cout << "pays[today]: " << pays[today] << endl;
        bestProfit[today] = max(bestProfit[today], bestProfit[chosen] + pays[today]);
        bestProfit[maxDay] = max(bestProfit[maxDay], bestProfit[today] + pays[maxDay]);

        int value = bestProfit[today] - pays[today];
        cout << "찾을 value: " << value << endl;
        if (value > 0)
        {
            auto chosenPos = find(bestProfit.begin(), bestProfit.begin() + today, value);
            if (chosenPos != bestProfit.begin() + today)
            {
                chosen = chosenPos - bestProfit.begin();
                cout << "chosen :" << chosen << endl;
            }
        }
    }
    else
    {
        bestProfit[today] = 0;
    }
}

int main()
{
    // 1. 입력 받기
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        int day, pay;
        cin >> day >> pay;

        days.push_back(day);
        pays.push_back(pay);
        bestProfit.push_back(0);
    }

    // 2. 백준이가 얻는 최대 수익 찾기
    // 오늘 얻을 수 있는 최대 수익은?
    for (int i = 1; i < N + 1; i++)
    {
        findBestProfit(i);
        cout << bestProfit[i] << endl;
    }

    // 3. 출력
    cout << *max_element(bestProfit.begin(), bestProfit.end()) << endl;

    return 0;
}