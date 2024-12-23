/*

문제: 1260번 DFS와 BFS
- 시간 제한: 2초, 메모리: 128MB

- 그래프를 DFS로 탐색한 결과와 BFS로 탐색한 결과를 출력하는 프로그램
- 단, 방문할 수 있는 정점이 여러개인 경우에는, 정점 번호가 작은 것을 먼저 방문
- 더 이상 방문할 수 있는 점이 없는 경우 종료함
- 정점 번호는 1 ~ N까지 존재

- 입력: 정점 개수 N(1 ~ 1000), 간선개수 M(1 ~ 10,000), 탐색을 시작할 정점의 번호 V,
        다음 줄에는 간선이 연결하는 두 정점의 번호, 두 정점 사이에는 여러 개의 간선이 있을 수 있으며, 주어진 간선은 양방향으로 이어져있음
- 출력: V부터 방문한 점을 순서대로 출력. 첫째줄에는 DFS를 수행한 결과, 다음 줄에는 BFS를 수행한 결과 출력

*/

#include <iostream>
#include <unordered_set>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int> > graph;

// 계속 탐사하면서 나중에 들어온거 먼저 탐사
void dfs(int start)
{
    vector<int> visited(N + 1, 0);
    stack<int> s;

    // 1. 시작 위치 답사 대상에 추가
    s.push(start);

    // 2. 대상이 되는 node가 없을 떄까지, 대상 노드의 인접한 node를 연속적으로 답사
    while (!s.empty())
    {
        // 인접노드 확인
        int current = s.top();
        s.pop();

        if (!visited[current])
        {
            // 현재 위치 방문
            // 들어간 순서 != 방문순서 이므로, 실제 방문 순서대로 visited가 변경되어야
            // 이후에 들어가는 순서가 영향받지 않음
            visited[current] = 1;
            cout << current << " ";

            // 인접한 Node들 정렬 후 큰 순서대로 답사 대상에 추가
            // stack이므로 늦게 들어간 것 먼저 탐색됨
            sort(graph[current].begin(), graph[current].end(), greater<int>());

            for (int node : graph[current])
            {
                if (!visited[node])
                {
                    s.push(node);
                }
            }
        }
    }

    cout << endl;
}

// 계속 탐사하는데 들어온거 먼저 탐사
void bfs(int start)
{
    vector<int> visited(N + 1, 0);
    queue<int> q;

    // 1. 시작 노드를 queue에 넣어 탐사 대상으로 추가
    q.push(start);
    visited[start] = 1;

    // 2. 대상이 되는 노드에 인접한 노드가 없을 때까지 반복 탐사
    while (!q.empty())
    {
        // 가장 먼저 넣은 노드에 대해서 인접 노드 확인
        int current = q.front();
        q.pop();

        // 방문 노드
        cout << current << " ";

        // 인접한 Node들 정렬 후 작 순서대로 답사 대상에 추가
        // queue이므로 먼저 들어간 것 먼저 탐색됨
        sort(graph[current].begin(), graph[current].end());

        for (int node : graph[current])
        {
            if (!visited[node])
            {
                // 어차피 들어간 순서대로 방문하므로, 넣자마자 vistied를 변경해도 
                // 이후에 들어가는 순서에 영향 없음
                visited[node] = 1;
                q.push(node);
            }
        }
    }

    cout << endl;
}

int main()
{
    // 1. 입력
    cin >> N >> M >> V;

    graph.resize(N + 1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;

        // 입력 받기
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 2. dfs
    dfs(V);

    // 3. bfs
    bfs(V);

    return 0;
}