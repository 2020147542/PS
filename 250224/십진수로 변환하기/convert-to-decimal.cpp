#include <iostream>

using namespace std;

string n;
int ans;

int main(){

    cin >> n;

    for(char c : n){
        ans = ans * 2 + (c - '0');
    }

    cout << ans << "\n";

    return 0;
}