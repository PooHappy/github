#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n;

	int start = 0;
	int end = n - 1;
	int min = 0;
	vector<int> v;
	int a = v[start], b = v[end];

	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}

	sort(v.begin(), v.end());

	min = abs(v[start] + v[end]);	//v[start]+v[end]의 절댓값을 min으로 지정

	while (start < end) {			//start가 end보다 작을동안
		if (abs(v[start] + v[end]) < min) {	//v[start]+v[end]의 절댓값이 min보다 작을 경우
			min = abs(v[start] + v[end]);	//min값 대입
			a = v[start];					//a와 b를 v[start]와 v[end]로 지정
			b = v[end];
		}
		if (abs(v[start]) > (abs(v[end]))) {//v[start]가 v[end]보다 절대값이 큰 경우
			start++;						//start값 증가
		}
		else {
			end--;							//반대의 경우 end 감소
		}
	}										//양쪽에서 포인터를 증가, 감소 시키며 더블 포인터로 탐색
	cout << a << " " << b;

	return 0;
}
