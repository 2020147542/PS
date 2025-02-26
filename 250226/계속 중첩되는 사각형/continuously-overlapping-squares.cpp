#include <iostream>
using namespace std;

int n, sum;
int x1, x2, y1, y2;
int grid[222][222];
bool isRed = true;

int main(){

    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> x1 >> y1 >> x2 >> y2;

        for(int x = x1 + 100; x < x2 + 100; x++){
            for(int y = y1 + 100; y < y2 + 100; y++){
                if(isRed){
                    grid[x][y] = 0;
                } else{
                    grid[x][y] = 1;
                }
            }
        }

        isRed = !isRed;
    }    

    for(int i = 0; i < 222; i++){
        for(int j = 0; j < 222; j++){
            sum += grid[i][j];
        }
    }

    cout << sum;

    return 0;
}