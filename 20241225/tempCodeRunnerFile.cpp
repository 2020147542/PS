/*

문제: 1012번 유기농 배추

- 1초, 512MB 안으로 풀어야 함
- 어떤 배추에 배추흰지렁이가 한 마리라도 살고 있으면,
    이 지렁이는 인접한 다른 배추로 이동할 수 있어, 그 배추들역시 해충으로부터 보호받을 수 있음
- 한 배추의 상하좌우 네 방향에 다른 배추가 있는 경우 서로 인접해 있다고 말함
- 배추들이 모여있는 곳에는 배추흰지렁이가 한 마리만 있으면 됨
- 배추들이 몇 군데에 퍼져있는지 조사하면 총 몇마리의 지렁이가 필요한지 알 수 있음
- 0은 배추가 심어져있지 않은 땅, 1은 배추가 심어져 있는 땅을 나타냄
- 두 배추의 위치가 같은 경우는 없음

- 입력: 테스트 케이스 개수 T,
    배추를 심은 배추밭의 가로길이 M(1~50), 세로길이 N(1~50), 배추가 심어져있는 위치의 개수 K(1~2500)
    배추의 위치 X(0~M-1), Y(0~N-1)
- 출력: 각 테스트 케이스에 대해서 필요한 최소의 배추흰지렁이 수 출력

*/

#include <iostream>
#include <vector>

using namespace std;

int grid[50][50];
int pos[50][2];
int M, N, K;

void input()
{
    int col = 0, row = 0;

    for (int count = 0; count < K; count++)
    {
        cin >> col >> row;

        grid[row][col] = 1;
        pos[count][0] = row;
        pos[count][1] = col;
    }
}

void dfs(int s_row, int s_col, int (&visited)[50][50])
{
    int dx[4] = {0, 0, -1, 1}; // 상하좌우 x 좌표 변화값
    int dy[4] = {1, -1, 0, 0}; // 상하좌우 y 좌표 변화값

    visited[s_row][s_col] = 1;

    for (int i = 0; i < 4; i++){

        int next_row = s_row + dy[i];
        int next_col = s_col + dx[i];

        if (next_row < 0 || next_row >= N) continue;
        if (next_col < 0 || next_col >= M) continue;
        if (grid[next_row][next_col] == 0) continue;

        if (!visited[next_row][next_col]){
            dfs(next_row, next_col, visited);
        }
    }
}

int solution()
{
    int visited[50][50] = {0};
    int now_row = 0, now_col = 0;
    int wormCount = 0;

    for (int i = 0; i < K; i++)
    {
        now_row = pos[i][0];
        now_col = pos[i][1];

        if (!visited[now_row][now_col])
        {
            wormCount++;
            dfs(now_row, now_col, visited);
        }
    }

    return wormCount;
}

int main()
{
    int T;
    cin >> T;
    vector<int> answers;

    for (int test_case = 0; test_case < T; test_case++)
    {
        memset(grid, 0, sizeof(grid));
        memset(pos, 0, sizeof(pos));

        cin >> M >> N >> K;

        input();

        answers.push_back(solution());
    }

    for(int answer: answers){
        cout << answer << endl;
    }

    return 0;
}