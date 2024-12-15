/*

문제: 1547번 공

- 컵 3개가 일렬로 존재 (왼쪽부터 1, 2, 3번)
- 1번 컵 아래에 공을 넣음
- 두 컵을 고른 후 위치 맞바꿈, 단 공의 위치는 그대로 있음
- 총 M번의 컵 위치를 변경한 후, 공이 들어있는 컵 번호는?

입력 : 컵의 위치를 바꾼 횟수 M(1 ~ 50), 그 다음 줄 부터는 서로 변경한 컵의 조합을 나타냄(X, Y)
출력 : 공이 들어있는 컵의 번호를 출력함. 공이 사라져서 컵 밑에 없는 경우에는 -1 출력

- 소요시간:

*/

#include <iostream>

using namespace std;

int main()
{

    // 1. 입력 받기
    int M;
    cin >> M;

    int ballLocation = 1;

    for (int i = 0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;

        /*
         * 2. 공의 위치 구하기
         * 공의 위치는 첫 번째 위치에 오는 컵의 위치 변화가 있을 때만 변함
         * 즉, 현재 1번 위치에 있는 컵이 나타났을 때만 트랙킹하여
         * 새로운 1번 자리 컵을 기억하고 있음
         */
        if (X == ballLocation)
        {
            ballLocation = Y;
        }
        else if (Y == ballLocation)
        {
            ballLocation = X;
        }
    }

    // 3. 마지막에 1번 자리에 있는 컵 출력하기
    cout << ballLocation << endl;

    return 0;
}