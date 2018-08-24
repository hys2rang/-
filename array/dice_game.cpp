/*
문제
1에서부터 6까지의 눈을 가진 3개의 주사위를 던져서 다음과 같은 규칙에 따라 상금을 받는 게임이 있다.
* 규칙(1) 같은 눈이 3개가 나오면 10,000원+(같은 눈)*1,000원의 상금을 받게 된다. 
* 규칙(2) 같은 눈이 2개만 나오는 경우에는 1,000원+(같은 눈)*100원의 상금을 받게 된다. 
* 규칙(3) 모두 다른 눈이 나오는 경우에는 (그 중 가장 큰 눈)*100원의 상금을 받게 된다.  
예를 들어, 3개의 눈 3, 3, 6이 주어지면 상금은 1,000+3 * 100으로 계산되어 1,300원을 받게 된다. 
또 3개의 눈이 2, 2, 2로 주어지면 10,000+2 * 1,000 으로 계산되어 12,000원을 받게 된다. 
3개의 눈이 6, 2, 5로 주어지면 그 중 가장 큰 값이 6이므로 6 * 100으로 계산되어 600원을 상금으로 받게 된다.
N(2≤N≤1,000) 명이 주사위 게임에 참여하였을 때, 가장 많은 상금을 받은 사람의 상금을 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 참여하는 사람 수 이 주어지고 그 다음 줄부터 N개의 줄에 사람들이 주사위를 던진 3개의 눈이 빈칸을 사이에 두고 각각 주어진다.

출력
첫째 줄에 가장 많은 상금을 받은 사람의 상금을 출력한다. 

예제 입력
3
3 3 6
2 2 2
6 2 5
예제 출력
12000 
*/

#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n,max;
	vector<vector <int>> arr;
	vector<int> sum;
	cin >> n;
	arr.resize(n, vector<int> (3,0));
	sum.resize(n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		if ((arr[i][1] == arr[i][0]) && (arr[i][1]==arr[i][2]) && (arr[i][0] == arr[i][2])) {
			sum[i] = 10000 + arr[i][0] * 1000;
			continue;
		}
		else if (arr[i][0] == arr[i][1]) {
			sum[i] = 1000 + arr[i][0] * 100;
			continue;
		}
		else if (arr[i][1] == arr[i][2]) {
			sum[i] = 1000 + arr[i][0] * 100;
			continue;
		}
		else if(arr[i][0] == arr[i][2]) {
			sum[i] = 1000 + arr[i][0] * 100;
			continue;
		}
		else {
			max = arr[i][0];
			for (int j = 1; j < 3; j++) {
				if (max < arr[i][j]) {
					max = arr[i][j];
				}
			}
			sum[i] = max * 100;
		}
	}

	max = sum[0];
	for (int i = 1; i < n; i++) {
		if (max < sum[i]) {
			max = sum[i];
		}
	}

	cout << max << endl;

	return 0;
}
