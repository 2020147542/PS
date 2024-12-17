/*

문제: 2578 빙고

- 제한 시간 : 1초, 메모리 제한 128MB
- 25칸에 1 ~ 25까지 자연수를 한 칸에 하나씩 씀
- 사회자가 부르는 수를 차례로 지움
- 같은 가로줄, 세로줄 또는 대각선 위에 있는 5개의 모든 수가 지워지는 경우 그 줄에 선을 긋는다
- 선이 세 개 이상 그어지는 순간 "빙고"라고 외치는데, 가장 먼저 외치는 사람이 게임의 승자
- 사회자가 몇 번째 수를 부른 후 철수가 "빙고"를 외치게 되는가?

- 입력: 1 ~ 5줄 > 철수의 빙고판 / 6 ~ 10즐 > 사회자가 부르는 수, 1 ~ 25까지의 수가 한 번씩 사용됨
- 출력: 철수가 빙고를 외칠 때, 사회자가 부른 수는 몇 번째 수인가

- 소요시간: 2시간
- 예제 1은 성공

*/

#include <iostream>

using namespace std;

const int WIDTH = 5;

int bingoBoard[WIDTH][WIDTH] = {-1};
int bingoLine = 0;

// 새로선 존재하는지 확인
void find_x(int col)
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (bingoBoard[i][col] != 0)
        {
            return;
        }
    }

    bingoLine++;
}

// 가로선 존재하는지 확인
void find_y(int row)
{
    for (int i = 0; i < WIDTH; i++)
    {
        if (bingoBoard[row][i] != 0)
        {
            return;
        }
    }

    bingoLine++;
}

// 대각선 존재하는지 확인
// 생각하지 못한 반례) 2,2 일 경우 2가지에 모두 해당
void find_cross(int position[2])
{
    // 경우 1) 좌측 상단 ~ 우측 하단 - x와 y 좌표 동일
    if (position[0] == position[1])
    {
        for (int i = 0; i < WIDTH; i++)
        {
            if (bingoBoard[i][i] != 0)
            {
                return;
            }
        }

        bingoLine++;
    }

    // 경우 2) 좌측 하단 ~ 우측 상단 - x와 y 좌표 합 4
    if ((position[0] + position[1]) == (WIDTH - 1))
    {
        for (int i = 0; i < WIDTH; i++)
        {
            if (bingoBoard[(WIDTH - 1) - i][i] != 0)
            {
                return;
            }
        }

        bingoLine++;
    }
}

// 특정 번호의 빙고판 위치 찾기
void checkBingoBoard(int num, int position[2])
{
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            if (bingoBoard[i][j] == num)
            {
                position[0] = i; // row
                position[1] = j; // col

                bingoBoard[i][j] = 0;

                return;
            }
        }
    }
}

int main()
{
    // 1. 빙고판 입력 받기
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cin >> bingoBoard[i][j];
        }
    }

    // 1-1. 사회자가 부르는 순서 입력 받기
    int said[WIDTH][WIDTH] = {-1};
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            cin >> said[i][j];
        }
    }

    /*
     * 2. 빙고 게임 진행
     * 한 번 지울 때마다, 해당 위치의 가로줄/세로줄/대각선이 모두 x로 되어 있는 경우 확인
     * 선이 하나라도 발견되면 +1씩 해서 3이 되는 경우의 숫자 return
     * 한 번 갔던 곳은 다시 가지 않으므로, 긋는 선이 겹칠 일은 없음
     */
    for (int i = 0; i < WIDTH; i++)
    {
        for (int j = 0; j < WIDTH; j++)
        {
            // 2-0. 현재 위치
            int current = i * WIDTH + j + 1;

            // 2-1. 위치 찾기
            int position[2] = {0, 0}; // row, col
            checkBingoBoard(said[i][j], position);

            // 2-2. 세로줄 있는지 확인
            find_y(position[0]);

            // 2-3. 가로줄 있는지 확인
            find_x(position[1]);

            // 2-4. 대각선 줄 있는지 확인
            find_cross(position);

            // 3. 출력 bingo가 3개 이상인지 확인
            // 이번 차례에 3이 넘어가도, 이번 차례가 몇번째인지만 출력하면 됨
            if (bingoLine >= 3)
            {
                cout << current << endl;
                return 0;
            }
        }
    }

    return 0;
}