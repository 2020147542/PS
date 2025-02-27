#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c;
int ans;

bool check(int &a, int &b, int &c){
    int s, m, l;

    s = min({a, b, c});
    l = max({a, b, c});

    if(c != s && c != l){
        m = c;
    }else if(a != s && a != l){
        m = a;
    }else if(b != s && b != l){
        m = b;
    }

    a = s;
    b = m;
    c = l;

    return a + 1 == b && b + 1 == c;
}

int main(){
    cin >> a >> b >> c;

    while(true){
        if(check(a, b, c)) break;

        if(a + 1 != b){
            if(b - a > 2){
                c = a + 2;
            }else if(b - a == 2){
                c = a + 1;
            }
        }else{
            if(c - b > 2){
                a = b + 2;
            } else if(c - b == 2){
                a = b + 1;
            }
        }
        ans++;
    }

    cout << ans;
    return 0;
}