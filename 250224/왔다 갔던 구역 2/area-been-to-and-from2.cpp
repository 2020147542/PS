#include <iostream>

using namespace std;

int n, cur, area;
int x[100];
char dir[100];
int line[2001];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> dir[i];
    }

    // Write your code here!
    cur = 1000;
    for (int i = 0; i < n; i++) {
        int a, b;

        if(dir[i] == 'L'){
            a = cur - x[i];
            b = cur;
            cur = a;
        } else{
            a = cur;
            b = cur + x[i];
            cur = b;
        }

        for(int j = a; j < b; j++){
            if(++line[j] == 2) area++;
        }
    }

    cout << area << "\n";

    return 0;
}