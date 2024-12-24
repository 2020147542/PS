/*

문제: 11724번 연결 요소의 개수

- 제한시간: 3초, 메모리 512MB
- 방향없는 그래프가 주어졌을 때, 연결 요소(연결된 요소의 묵음)의 개수를 구하여라

- 입력: 정점의 개수 N(1~1000)과 간선의 개수 M(0 ~ n(n-1)/2)),
    둘째 줄부터 M개의 줄에 간선의 양 끝점 u와 v, 이때 1 ≤ u, v ≤ N, u와 v는 같지 않음
    같은 간선은 한 번만 주어짐
- 출력: 연결 요소의 개수

*/

#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>

using namespace std;

int findNonVisitedNodeIndex(vector<int> &visited, int &N)
{
    for (int idx = 0; idx < N; idx++)
    {
        if (!visited[idx])
            return idx;
    }

    return -1;
}

void solution(vector<int>& visited, vector<vector<int> >& graph, int start_node)
{
    stack<int> s;
    s.push(start_node);

    while (!s.empty())
    {
        int current = s.top();
        s.pop();

        if (!visited[current]){
            visited[current] = 1;
        }

        for (int next: graph[current]){
            if(!visited[next]){
                s.push(next);
            }
        }
    }
}

int main(){

    int N, M;
    cin >> N >> M;

    vector<vector<int> > graph(N);

    for (int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;

        graph[u-1].push_back(v-1);
        graph[v-1].push_back(u-1);
    }

    vector<int> visited(N, 0);
    
    for (int con_comp = 0; true; con_comp++){
        int index = findNonVisitedNodeIndex(visited, N);

        if (index > -1){
            solution(visited, graph, index);
        }else{
            cout << con_comp << endl;
            return 0;
        }
    }

    return 0;
}