#include <iostream>
using namespace std;

int n; 
int recur(int idx){
    if(idx <= 2) return idx;

    return recur(idx / 3) + recur(idx-1);
}

int main(){
    cin >> n;

    cout << recur(n) << endl;

    return 0;
}