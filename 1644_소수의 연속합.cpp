#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <math.h>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n;
	int start = 0;
	int save_start = 0;
	int sum = 0;
	int count = 0;

	cin >> n;

	vector<int> v1 = { 0,0 };
	int b = sqrt(n);
	vector<int> v3;
	//2부터 n까지의 수 저장
	for (int i = 2; i <= n; i++) {
		v1.push_back(i);
	}
	//v1[j]가 소수가 아니면 0으로 치환
	for (int i = 2; i <= b; i++) {
		for (int j = i + i; j < v1.size(); j += i) {
			if (v1[j] == j)
				v1[j] = 0;
		}
	}
	//v1[i]가 소수면 v3에 저장
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != 0)
			v3.push_back(v1[i]);
	}
	//v3의 사이즈동안 진행
	while (start < v3.size()) {
		sum += v3[start];			//sum = v3의 start부터 누적
		if (sum == n) {				//sum이 n과 동일하면
			start = ++save_start;	//save_start 선 증가 후 start 지정
			count++;				//연속합에 해당하는 횟수 증가
			sum = 0;				//sum 초기화
		}
		else if (sum < n) {			//n이 sum보다 크다면
			start++;				//start 증가
		}
		else if (sum > n) {			//n이 sum보다 작으면
			start = ++save_start;	//save_start 선 증가후 start 지정
			sum = 0;				//sum 초기화
		}
	}
	cout << count;					//count 횟수 출력

	return 0;
}