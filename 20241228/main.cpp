/*

문제: 12851번 숨바꼭질 2

- 수빈이는 현재 N(0 ~ 100,000) 위치
- 동생은 현재 K(0 ~ 100,000) 위치
- 수빈이는 걷거나 순간이동 가능 (X일 때 걷는다면 1초 후에 X-1 OR X+1 OR 2*X)
- 수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인가
- 가장 빠른 시간으로 찾는 방법이 몇 가지 인지 구하는 프로그램

- 입력: 수빈이가 있는 위치 N, 동생이 있는 위치 K
- 출력: 첫째 줄) 수빈이가 동생을 찾는 가장 빠른 시간
		둘째 줄) 가장 빠른 시간으로 수빈이가 동생을 찾는 방법의 수

*/

#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, K;
int dr[3] = {1, 1, 2};
int dx[3] = {-1, 1, 0};

const int maxLength = 100001;
pair<int, int> visited[maxLength];

pair<int, int> solution(int start_node)
{

	int fastestLevel = 0;
	int fastestWays = 0;
	queue<int> q;

	visited[start_node] = {fastestLevel, fastestWays + 1};
	q.push(start_node);

	while (!q.empty())
	{
		int curNode = q.front();
		int curLevel = visited[curNode].first;
		int curCount = visited[curNode].second;
		q.pop();

		if (curNode == K)
		{
			fastestLevel = fastestWays == 0 ? curLevel : fastestLevel;
			fastestWays += curCount;
		}

		if (fastestLevel && fastestLevel < curLevel) break;

		for (int i = 0; i < 3; i++)
		{
			int nextNode = dr[i] * curNode + dx[i];
			if (nextNode >= 0 && nextNode < maxLength)
			{
				if (visited[nextNode].first && visited[nextNode].first == curLevel + 1) {
					visited[nextNode].second += curCount;
				}
				else if(visited[nextNode].first == 0 && nextNode != start_node) {
					visited[nextNode].first = curLevel + 1;
					visited[nextNode].second += curCount;
					q.push(nextNode);
				}
			}
		}
	}

	return {fastestLevel, fastestWays};
}

int main()
{

	cin >> N >> K;

	pair<int, int> result = solution(N);
	cout << result.first << endl;
	cout << result.second << endl;

	return 0;
}
