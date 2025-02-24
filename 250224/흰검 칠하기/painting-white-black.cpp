#include <iostream>
#include <cstring>
using namespace std;

int n, cur;
int x[1000];
char dir[1000];
int line[200001][3];
int aa, bb, cc;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    cur = 100000;
    for (int i = 0; i < n; i++) {

        int a, b;
        if(dir[i] == 'L') {
            for(int j = cur; j > cur - x[i]; j--) {
                if(line[j][2] == 3) continue;

                line[j][0]++;
                line[j][2] = 1;

                if (line[j][0] >= 2 && line[j][1] >= 2) line[j][2] = 3;
            }
            cur = cur - x[i] + 1;

        } else{
           for(int j = cur; j < cur + x[i]; j++) {
                if(line[j][2] == 3) continue;

                line[j][1]++;
                line[j][2] = 2;

                if (line[j][0] >= 2 && line[j][1] >= 2) line[j][2] = 3;
            }
            cur = cur + x[i] - 1;
        }
    }
    
    // 흰색, 검은색, 회색의 타일 수 출력
    for(int i = 0; i <= 200001; i++){
        if(line[i][2] == 1) aa++;
        else if(line[i][2] == 2) bb++;
        else if(line[i][2] == 3) cc++;
    }

    cout << aa << " " << bb << " " << cc << endl;

    return 0;
}