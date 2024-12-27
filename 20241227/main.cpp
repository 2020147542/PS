/*

문제: 1697번 숨바꼭질

- 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고
- 동생은 점 K(0 ≤ K ≤ 100,000)에 있다
- 수빈이는 걷거나 순간이동이 가능
    x일때 걷는 다면 1초 후 x-1 또는 x+1 가능
    x일때 순간이동하면 1초후 2*x로 이동
- 수빈이가 동생을 찾을 수 있는 가장 빠른 시간은?

- 입력: 수빈이가 있는 위치 N, 동생이 있는 위치 K
- 출력: 수빈이가 동생을 찾는 가장 빠른 시간 출력

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int N, K;
int dr[3] = {1, 1, 2};
int dx[3] = {-1, 1, 0};
const int MAX_NUM = 100001;

int solution(int cx)
{
    int level = 0;
    vector<bool> visited(MAX_NUM, false);
    queue<pair<short, int> > q;

    q.push({level, cx});
    visited[cx] = 1;

    while (!q.empty())
    {
        int curLevel = q.front().first;
        int current = q.front().second;
        q.pop();

        if (current == K) {
            level = curLevel;
            break;
        };

        for (int i = 0; i < 3; i++)
        {
            int nx = (dr[i] * current) + dx[i];
            if (nx >= 0 && nx < MAX_NUM && !visited[nx])
            {
                visited[nx] = 1;
                q.push({curLevel + 1, nx});
            }
        }
    }

    return level;
}

int main()
{
    cin >> N >> K;

    cout << solution(N) << endl;

    return 0;
}