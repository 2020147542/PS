#include <iostream>

using namespace std;

int n, m, p, cnt;
bool sus[26];
char c[100];
int u[100];

int main() {
    cin >> n >> m >> p;

    for (int i = 0; i < m; i++) {
        cin >> c[i] >> u[i];
    }

    if(u[p-1] == 0){
        cout << "";
        return 0;
    }

    for(int i = m - 1; i >= p - 1; i--){
        if(!sus[c[i] - 'A']){
            sus[c[i] - 'A'] = true;
            cnt++;
        }
    }

    if(n - cnt > u[p - 1]){
        for(int i = p - 2; i >= 0; i--){
            if(u[i] != u[p-1]) break;
            sus[c[i] - 'A'] = true;
        }
    }

    for(int i = 0; i < n; i++){
        if(!sus[i]){
            cout << (char)(i + 'A') << " ";
        }
    }

    return 0;
}