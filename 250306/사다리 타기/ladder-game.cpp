#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int n, m, min_val = INT_MAX; 
int a[20];
int b[20];
bool visited[20][20];
vector<int> ans;

bool isSame(const vector<int> &result){

    for(int i = 1; i <= n; i++){
        if(ans[i] != result[i]) return false; 
    }

    return true;
}

void game(int idx, int cnt){
    if(idx == m) {
        // 사다리 게임
        vector<int> result(n+1, 0);
        for(int i = 1; i <= n; i++){
            int now = i;

            for(int d = 1; d <= 15; d++){
                if(visited[d][now]) now++;
                else if(visited[d][now-1]) now--;
            }
            result[i] = now;
        }

        if(cnt == m) {
            ans = result;
            min_val = m;
        } else if(isSame(result)){
            min_val = min(min_val, cnt);
        }
        return;
    }

    visited[b[idx]][a[idx]] = true;
    game(idx + 1, cnt + 1);
    visited[b[idx]][a[idx]] = false;
    game(idx + 1, cnt);
}

int main(){

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
    }

    game(0, 0);
    cout << min_val;

    return 0;
}