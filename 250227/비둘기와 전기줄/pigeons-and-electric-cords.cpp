#include <iostream>
#include <cstring>
using namespace std;

int N, ans;
int pigeon[100];
int position[100];
int way[11];
int direct[11];

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> pigeon[i] >> position[i];
    }

    // Please write your code here.
    memset(direct, -1, sizeof(direct));

    for (int i = 0; i < N; i++) {

        int pig = pigeon[i];
        int pos = position[i];

        if(direct[pig] == -1){
            direct[pig] = pos;
        }

        if(direct[pig] != pos){
            way[pig]++;
            direct[pig] = pos;
        }
    }

    for (int i = 1; i < 11; i++) {
        ans += way[i];
    }

    cout << ans;

    return 0;
}