#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int d[2] = {-1, 1};
int n, m, h, k;
bool tree[100][100];
int ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h >> k;
    // 술래는 정 가운데서 달팽이 모양으로 움직임    
    int x = ceil(n / 2.0), ceil(y = n / 2.0);

    // 도망자
    vector<tuple<int, int, int>> runner;
    for(int i = 0; i < m; i++){
        int a, b, d;
        cin >> a >> b >> d;
        runner.push_back(make_tuple(a, b, d));
    }

    // 나무 - 도망자와 같은 위치에 존재 가능
    for(int i = 0; i < h; i++){
        int a, b;
        cin >> a >> b;
        grid[a][b] = true;
    }

    // m명의 도망자가 움직이고, 그 다음 술래가 움직이고 k번 반복
    for(int i = 0; i < k; i++){

        // 술래와의 거리가 3이하인 도망자만 움직임
        // 좌우 or 상하로만 움직일 수 있음
        // 좌우 = 항상 오르쪽을 보고 시작
        // 상하 = 항상 아래쪽을 보고 시작

        // 그 다음 술래가 달팽이 모양으로 움직임
        // 도망자 잡기
        // 현재 방향에서 현재칸 포함 총 3칸 + 나무 위치 제외
        // 점수 = 현재 턴 * 현재 턴에서 잡힌 도망자 수
        // 잡히면 사라짐
    }

    return 0;
}