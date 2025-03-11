#include <iostream>
#include <vector>
#include <climits>
#include <set>
using namespace std;
typedef pair<int, int> pir;

int n, m, t;
int arr[22][22];
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
vector<pir> visited;

bool inRange(int r, int c){
    if(r < 0 || r >= n || c < 0 || c >= n) return false;
    return true;
}

int main() {
    // Please write your code here.
    cin >> n >> m >> t;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < m; i++){
        int r, c;
        cin >> r >> c;
        visited.push_back(pir(r-1, c-1));
    }

    for(int i = 0;  i < t; i++){
        set<pir> result;
        set<pir> remove;

        for(auto ele: visited){
            int max_val = INT_MIN;
            int fr = -1, fc = -1;

            for(int k = 0; k < 4; k++){
                int nr = ele.first + dr[k];
                int nc = ele.second + dc[k];

                if(inRange(nr, nc) && arr[nr][nc] > max_val){
                    max_val = arr[nr][nc];
                    fr = nr;
                    fc = nc;
                }
            }

            if(remove.count(pir(fr, fc))) continue;
            if(result.count(pir(fr, fc))){
                remove.insert(pir(fr, fc));
                result.erase(pir(fr, fc));
            } else{
                result.insert(pir(fr, fc));
            }
        }

        visited = vector<pir>(result.begin(), result.end());
    }

    cout << visited.size();
    return 0;
}