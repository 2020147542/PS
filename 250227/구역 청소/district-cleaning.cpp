#include <iostream>
#include <algorithm>
using namespace std;

int a, b, c, d;
int line[111];

int main(){
    cin >> a >> b >> c >> d;

    if(b < c || d < a){
        cout << (b-a) + (d-c); 
    }else{
        cout << max(b, d) - min(a, c);
    }

    return 0;
}