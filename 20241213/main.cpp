/*

문제: 1018 체스판 다시 칠하기

- 보드: MxN개의 정사각형
- 정사각형 중 일부가 검정, 나머지는 흰색
- 지민이는 이 보드를 잘라서 8X8 체스판으로 만들려고 함
- 체스판이 되기 위해서 8X8 보드를 칠한다고 할 때, 다시 칠해야하는 정사각형의 최소 개수 구하기

입력 : n, m이 주어지며 8 ~ 50 사이의 수, 각 줄에는 보드 각 행의 상태가 주어짐(B: 검은색, W: 흰색)
출력 : 지민이가 다시 칠해야하는 정사각형 개수의 최소값

소요시간: 1시간 30분

*/

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

vector<string> board;

/*
 * 각 보드마다 검정으로 시작하는 경우, 흰색으로 시작하는 경우와 비교한 후,
 * 다른 부분의 갯수가 최소가 되는 값을 return 한다.
 */
int compareWith(int s_row, int s_col)
{

    int black = 0; // 좌측 상단이 검정인 경우, 변경해야할 타일 수
    int white = 0; // 좌측 상단이 흰색인 경우, 변경해야할 타일 수

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 != 0 && j % 2 != 0))
            {
                black += board[s_row + i][s_col + j] == 'B' ? 0 : 1;
                white += board[s_row + i][s_col + j] == 'W' ? 0 : 1;
            }
            else
            {
                black += board[s_row + i][s_col + j] == 'W' ? 0 : 1;
                white += board[s_row + i][s_col + j] == 'B' ? 0 : 1;
            }
        }
    }

    return min(black, white);
}

int main()
{
    // 1. 입력받기
    int N, M;
    cin >> N >> M; // 8 ~ 50

    string line;
    for (int i = 0; i < N; i++)
    {
        cin >> line;
        board.push_back(line);
    }

    /*
     * 2. 다시 칠해야하는 정사각형의 수가 최소가 되는 경우 구하기
     * 전체 크기를 8x8 보드로 나눠서 각각의 보드에서 최소 다시 칠해야하는 개수를 구함
     */
    vector<int> result;
    for (int r = 0; r + 7 <= N - 1; r++)
    {
        for (int c = 0; c + 7 <= M - 1; c++)
        {
            result.push_back(compareWith(r, c));
        }
    }

    // 3. 각 보드들의 최소 색칠 값 중의 최소를 골라 출력
    cout << *min_element(result.begin(), result.end()) << endl;

    return 0;
}