#include <iostream>
using namespace std;

int N;

void f1(int n){
    if(n == 0) return;

    f1(n - 1);
    cout << n << " ";
}

void f2(int n){
    if(n == 0) return;

    cout << n << " ";
    f2(n - 1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    f1(N);
    cout << "\n";
    f2(N);

    return 0;
}