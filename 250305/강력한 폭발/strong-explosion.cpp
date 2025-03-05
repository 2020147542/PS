#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> pir;

int n, ans;
int grid[22][22];
int blue[22][22];
vector<pir> bombs;
pir d[3][4] = {{{-2, 0}, {-1, 0}, {1, 0}, {2, 0}}, {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}, {{-1, 1}, {1, 1}, {1, -1}, {-1, -1}}};

void bomb(int idx){
    if(idx >= bombs.size()){
        int cnt = 0;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(blue[i][j] > 0) cnt++;
            }
        }
        ans = max(ans, cnt);
        return;
    }

    for(int k = 0; k < 3; k++){
        int nr = 0, nc = 0;

        for(int i = 0; i < 4; i++){
            nr = bombs[idx].first + d[k][i].first;
            nc = bombs[idx].second + d[k][i].second;

            if(nr >= n || nr < 0 || nc >= n || nc < 0) continue;
            blue[nr][nc]++;
        }
        bomb(idx + 1);
        for(int i = 0; i < 4; i++){
            nr = bombs[idx].first + d[k][i].first;
            nc = bombs[idx].second + d[k][i].second;

            if(nr >= n || nr < 0 || nc >= n || nc < 0) continue;
            blue[nr][nc]--;
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];

            if(grid[i][j]){
                bombs.push_back(pir(i, j));
                blue[i][j]++;
            }
        }
    }

    bomb(0);
    cout << ans;
    return 0;
}