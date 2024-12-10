/*

문제: 2309번 일곱 난쟁이

- 난쟁이 9명이 있음. 모두 자신이 7명 안에 속한다고 주장
- 일곱 난쟁이 키 합 = 100

입력 : 9명의 난쟁이의 키(100 이하 자연수), 모두 다름
출력 : 일곱 난쟁이에 속하는 키 오름차 순으로 출력, 정답이 없는 경우는 없고/ 여가가지인 경우 아무거나 출력

1차 문제 해석 소요시간 : 3분
총 소요시간(19:52 ~ 20:48): vector와 sort 첫 사용으로 인한 구현에 어려움을 겪음.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{

    // 1. 9명의 키 배열 입력으로 받기 -> 길이가 정해진 값이므로 배열
    int h = 0;
    int sum = 0;
    vector<int> heights;

    for (int i = 0; i < 9; i++)
    {
        cin >> h;
        heights.push_back(h);
        sum += h;
    }

    /*
     * 2. 7명의 난쟁이 구하기
     * 9개 중 7개를 골라서 다 더했을 때 100이 되어야 함 = 9개 중에 2개를 골라서 그 합을 전체 총합에서 빼기
     * 9C2 = 9!/(7!2!) = 9*4= 36개의 조합
     * 뺀 값이 100이면 바로 return
     */
    int maximum = -1;
    int minimum = -1;

    for (int j = 0; j < 9; j++)
    {
        for (int k = j + 1; k < 9; k++)
        {
            int rest = heights[j] + heights[k];
            if (sum - rest == 100)
            {

                // j와 k 중에서 큰 값 먼저 삭제
                maximum = j > k ? j : k;
                minimum = j < k ? j : k;
                heights.erase(heights.begin() + maximum);
                heights.erase(heights.begin() + minimum);

                sort(heights.begin(), heights.end());

                for (int height : heights)
                {
                    cout << height << endl;
                }

                return 0;
            }
        }
    }

    return 0;
}