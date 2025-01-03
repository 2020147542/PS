/*

문제: 1495번 기타리스트

- 2초 이내, 128MB로 제한되어 있음
- 다가오는 공연에서 연주할 N개의 곡을 연주하고 있다
- 매번 곡이 시작하기 전에 볼륨을 바꾸고 연주하려고 한다
- 각각의 곡이 시작하기 전에 바꿀 수 있는 볼륨의 리스트를 만들었다
    v[i] = i번째 곡을 연주하기 전에 바꿀 수 있는 볼륨
    현재볼륨 = p라면, i번 곡은 p+v[i] || p-v[i]로 연주해야 함
- 단, 0보다 작은 값으로 볼륨을 바꾸거나, m보다 큰 값으로 볼륨을 바꿀 수 없다.
- 곡의 개수 n과 시작 볼륨 s, 그리고 m이 주어졌을 때, 마지막 곡을 연주할 수 있는 볼륨 중 최댓값은?
- 모든 곡은 리스트에 적힌 순서대로 연주해야함

- 입력: n(1 ~ 50), s(0 ~ m), m(1 ~ 1000)
    둘째줄부터 각 곡이 시작하기 전에 줄 수 있는 볼륨의 차이가 주어짐(1 ~ m)
- 출력: 마지막 곡의 볼륨 중 최대값 출력, 마지막 곡을 연주할 수 없다면(=중간에 볼륨 조절이 불가능할 경우) -1 출력

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, S, M;
int maxVol = -1;
vector<int> vol;

void findMaxVol(int index, int start){
    if (start == -1) {
        return;
    }

    if (index == N + 1) {
        maxVol = start > maxVol ? start : maxVol;
        return;
    };

    int down = start - vol[index] < 0 ? -1 : start - vol[index];
    int up = start + vol[index] > M ? -1 : start + vol[index];

    findMaxVol(index + 1, down);
    findMaxVol(index + 1, up);
}

int main()
{
    cin >> N >> S >> M;

    vol.resize(N+1, 0);
    for (int i = 1; i <= N; i++){
        cin >> vol[i];
    }

    findMaxVol(1, S);
    cout << maxVol << endl;

    return 0;
}