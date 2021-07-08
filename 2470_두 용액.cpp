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

	min = abs(v[start] + v[end]);	//v[start]+v[end]�� ������ min���� ����

	while (start < end) {			//start�� end���� ��������
		if (abs(v[start] + v[end]) < min) {	//v[start]+v[end]�� ������ min���� ���� ���
			min = abs(v[start] + v[end]);	//min�� ����
			a = v[start];					//a�� b�� v[start]�� v[end]�� ����
			b = v[end];
		}
		if (abs(v[start]) > (abs(v[end]))) {//v[start]�� v[end]���� ���밪�� ū ���
			start++;						//start�� ����
		}
		else {
			end--;							//�ݴ��� ��� end ����
		}
	}										//���ʿ��� �����͸� ����, ���� ��Ű�� ���� �����ͷ� Ž��
	cout << a << " " << b;

	return 0;
}
