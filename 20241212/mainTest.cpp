#include <iostream>
using namespace std;

// 족보 계산 함수
int getRank(int x, int y)
{
    if (x == y) // 땡
    {
        return x + 10;
    }
    return (x + y) % 10; // 끗
}

int main()
{
    int A, B;
    cin >> A >> B;
    int cards[18] = {0}, idx = 0;

    for (int i = 1; i <= 10; i++)
    {
        if (i == A && i == B)
        {
            continue;
        }
        else if (i == A || i == B)
        {
            cards[idx++] = i;
        }
        else
        {
            cards[idx++] = i;
            cards[idx++] = i;
        }
    }

    int younghakRank = getRank(A, B); // 영학이의 족보 계산
    int totalCases = 0, winCases = 0;

    for (int i = 0; i < 18; i++)
    {
        for (int j = i + 1; j < 18; j++)
        {
            int opponentRank = getRank(cards[i], cards[j]);
            totalCases++;

            // 영학이가 이길 경우
            if (younghakRank > opponentRank)
            {
                winCases++;
            }
        }
    }

    // 승률 계산
    double winProbability = (double)winCases / totalCases;

    // 출력 (소수점 셋째 자리까지)
    cout << fixed;
    cout.precision(3);
    cout << winProbability << endl;

    return 0;
}
