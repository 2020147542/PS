/*

문제: 10448번 유레카 이론

- 삼각수: n(n+1)/2
- 모든 자연수는 최대 3개의 삼각수 합으로 표현 가능
- 그중 정확히 3개의 삼각수의 합으로 나타낼 수 있는 프로그램 만들기
- 단, 모든 삼각수가 달라야할 필요는 없음.

입력 : 테스트 케이스 개수 + 각 테스트 케이스 k(3 ~ 1000)가 한 줄에 하나씩 존재
출력 : 정확히 3개의 삼각수 합으로 구성된다면 1, 아니면 0을 테스트 케이스 순서대로 한 줄에 하나씩 출력

풀이시간: 40분(1차만에 성공)
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * 작은 수부터 arr에서 2개를 고르고, 해당 합이 m이라 하면
 * k - m이 arr에 있는지 확인.
 * 가능한 모든 조합을 확인해보고 없다면 0 반환
 * 있다면 바로 1 반환
 */
int checkIfAnswer(int k, vector<int> list)
{
    for (int i = 0; i < list.size(); i++)
    {
        for (int j = i; j < list.size(); j++)
        {
            int r = k - (list[i] + list[j]);
            if (find(list.begin(), list.end(), r) != list.end())
            {
                return 1;
            }
        }
    }

    return 0;
}

int main()
{

    int n;
    int k;
    vector<int> arr;

    // 1. 전체 테스트 케이스 입력받아서 배열에 저장
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        arr.push_back(k);
    }

    /*
     * 2. 삼각수 구하기
     * 미리 삼각수를 구해서 배열 안에 넣어둠
     * 최대 1000이니, 44*45/2 = 990이 최대 값
     */
    vector<int> triList;
    for (int j = 1; j < 45; j++)
    {
        int triValue = j * (j + 1) / 2;
        triList.push_back(triValue);
    }

    /*
     * 3. 삼각수 확인 및 출력
     */
    for (int l = 0; l < n; l++)
    {
        cout << checkIfAnswer(arr[l], triList) << endl;
    }

    return 0;
}