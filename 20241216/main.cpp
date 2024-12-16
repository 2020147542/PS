/*

문제: 20546 기적의 매매법

[주식 매매법]
1) BNP 전략
- 준현이는 한 번 산 주식은 절대 팔지 않는다.(2099년 까지)
- 주식을 살 수 있다면 가능한 만큼 무조건 최대한 많이 즉시 산다.
2) 33 매매법
- 성민이는 모든 거래는 전량 매수와 전량 매도로 이루어진다.
- 빚을 내서 주식하지 않는다.
- 3일 연속 가격이 전일 대비 상승할 경우, 주식은 다음날 무조건 가격이 하락한다고 가정한다.
- 즉, 현재 소유한 주식이 3일 내내 오르면, 3일째에 전량 매도한다.
- 3일 연속 가격이 전일 대비 하락할 경우, 주식은 다음날 무조건 가격이 상승한다고 가정한다.
- 즉, 주식이 3일 내내 하락하면, 3일째에 전량 매수한다.

[문제]
- 준현 vs 성민이의 수익률 대결
- MachineDuck 기업의 주식 거래만 가능하며, 2021/1/1 ~ 2021/1/14까지 가능
- 준현이와 성민이에게 주어진 현금은 동일하며, 매일 주식 거래가 가능
- 1월 14일에 (현금 + 1월 14일 주가x주식수)가 더 높은 사람이 이김
- 이때, 해당 기간동안의 주식 가격을 미리 안다면 누가 더 높은 수익률을 낼지 맞추기

- 입력: 현금, 14일 간의 주가가 공백(1000이하의 양의 정수)을 두고 차례로 주어짐
- 출력: 준현이가 더 많다면 BNP, 성민이가 더 크다면 TIMING, 동일하다면 SAMESAME 출력

- 소요시간: 1시간

*/

#include <iostream>

using namespace std;

const int TWO_WEEKS = 14;
int prices[TWO_WEEKS];

/*
 * 가진 돈에서 살 수 있는 주식 수,
 * 남은 돈 계산
 */
void paid(int &money, int &stocks, int days)
{
    if (money < prices[days])
    {
        return;
    }

    int buy = money / prices[days];
    stocks += buy;
    money -= buy * prices[days];
}

/*
 * 현재 가진 돈보다 주가가 낮다면, 살 수 있는 만큼 매수
 * 14일 동안 반복
 * 총 자산 = (현금 + 1월 14일의 주가 × 주식 수)
 */
int getBNP(int initialMoney)
{
    int finalMoney = 0;
    int stocks = 0;

    for (int i = 0; i < TWO_WEEKS; i++)
    {
        paid(initialMoney, stocks, i);

        if (i == TWO_WEEKS - 1)
        {
            finalMoney = initialMoney + stocks * prices[i];
        }
    }

    return finalMoney;
}

/*
 * 전량 매수 또는 전량 매도
 * 내가 주식을 가지고 있을 때부터 3일 기준으로 상승하면 3일째 전량 매도(최고점에 팔기) -> 보유주식: 0
 * 아무일로 부터 3일 기준으로 하락하면 3일 째 전량 매수(최저점에 사기)
 */
int getTiming(int initialMoney)
{
    int stocks = 0;

    for (int i = 3; i < TWO_WEEKS; i++)
    {
        if (stocks && (prices[i - 3] < prices[i - 2]) && (prices[i - 2] < prices[i - 1]) && (prices[i - 1] < prices[i]))
        {
            initialMoney += stocks * prices[i];
            stocks = 0;
            continue;
        }

        if ((prices[i - 3] > prices[i - 2]) && (prices[i - 2] > prices[i - 1]) && (prices[i - 1] > prices[i]))
        {
            paid(initialMoney, stocks, i);
            continue;
        }
    }

    return initialMoney + (stocks * prices[TWO_WEEKS - 1]);
}

int main()
{
    // 1. 입력 받기
    int money = 0;
    cin >> money;

    int days = 0;
    while (days < TWO_WEEKS)
    {
        cin >> prices[days];
        days++;
    }

    // 2. 준현이와 성민이가 번 돈 계산
    int junHyun = getBNP(money);
    int sungMin = getTiming(money);

    // 3. 경우에 따른 출력
    if (junHyun < sungMin)
    {
        cout << "TIMING" << endl;
        return 0;
    }

    if (junHyun > sungMin)
    {
        cout << "BNP" << endl;
        return 0;
    }

    cout << "SAMESAME" << endl;
    return 0;
}