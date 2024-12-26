/*

문제: 2667번 단지번호붙이기

- 1초, 128MB 내에 완료해야함
- 정사각형 모양의 지도
- 1: 집이 있는 곳, 0: 집이 없는 곳
- 상하좌우로 다른 집이 있는 경우를 연결되어 있다고 함
- 연결된 집의 모임인 단지를 정하려고함
- 이때 총 단지수와, 각 단지 별 집의 수를 오름차순으로 정렬해서 출력해야 함

- 입력: 지도 한 변의 길이 N(5~25), N줄에 지도 내부 값(1 또는 0)
- 출력: 첫번째 줄(총 단지 수), 이후 줄 부터, 각 단지 내 집의 수를 오름차 순으로 정렬하여 한 줄에 하나씩 출력

*/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int N;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

string map[25];
int visited[25][25] = {0};
int houseNum = 0;

void dfs(int start_row, int start_col) {

    houseNum++;
    visited[start_row][start_col] = true;

    for (int i = 0; i < 4; i++){
        int next_row = start_row + dy[i];
        int next_col = start_col + dx[i];

        if (next_row < 0 || next_row >= N) continue;
        if (next_col < 0 || next_col >= N) continue;
        if (map[next_row][next_col] == '0') continue;
        if (visited[next_row][next_col]) continue;

        dfs(next_row, next_col);
    }
}

void printOut(vector<int> &houseNums)
{

    cout << houseNums.size() << endl;

    sort(houseNums.begin(), houseNums.end());

    for (int houseNum : houseNums)
    {
        cout << houseNum << endl;
    }
}

void solution(vector<int> &houseNums) {

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++){
            
            if (map[row][col] == '0') continue;
            if (visited[row][col]) continue;

            houseNum = 0;
            dfs(row, col);
            houseNums.push_back(houseNum);
        }
    }

    printOut(houseNums);
}

int main() {
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> map[i];
    }

    vector<int> houseNums;

    solution(houseNums);

    return 0;
}