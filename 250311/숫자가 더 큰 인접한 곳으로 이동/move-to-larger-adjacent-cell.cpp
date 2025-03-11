#include <iostream>
using namespace std;

int n;
int r, c;
int arr[111][111];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

bool inRange(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return false;
    return true;
}

void move(int i, int j){
    int cur = arr[i][j];
    cout << cur << " ";

    for(int k = 0; k < 4; k++){
        int nr = dy[k] + i;
        int nc = dx[k] + j;
        
        if(inRange(nc, nr) && arr[nr][nc] > cur){
            move(nr, nc);
            return;
        }
    }
}

int main() {
    // Please write your code here.
    cin >> n;
    cin >> r >> c;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }

    move(r-1, c-1);
    return 0;
}