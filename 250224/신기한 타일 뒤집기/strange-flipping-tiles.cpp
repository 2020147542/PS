#include <iostream>

using namespace std;

int n, cur;
int x[1000];
char dir[1000];
int tile[200001];
int aa, bb;

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Write your code here!
    cur = 100000;
    for(int i = 0; i < n; i++){
        if(dir[i] == 'L'){
            for(int j = cur; j > cur - x[i]; j--){
                tile[j] = 1;
            }
            cur = cur - x[i] + 1;
        } else{
            for(int j = cur; j < cur + x[i]; j++){
                tile[j] = 2;
            }
            cur = cur + x[i] - 1;
        }
    }

    for(int i = 0; i <= 200001; i++){
        if(tile[i]== 1) aa++;
        else if(tile[i] == 2) bb++;
    }

    cout << aa << " " << bb << "\n";

    return 0;
}