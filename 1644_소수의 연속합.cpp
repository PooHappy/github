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
	//2���� n������ �� ����
	for (int i = 2; i <= n; i++) {
		v1.push_back(i);
	}
	//v1[j]�� �Ҽ��� �ƴϸ� 0���� ġȯ
	for (int i = 2; i <= b; i++) {
		for (int j = i + i; j < v1.size(); j += i) {
			if (v1[j] == j)
				v1[j] = 0;
		}
	}
	//v1[i]�� �Ҽ��� v3�� ����
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != 0)
			v3.push_back(v1[i]);
	}
	//v3�� ������� ����
	while (start < v3.size()) {
		sum += v3[start];			//sum = v3�� start���� ����
		if (sum == n) {				//sum�� n�� �����ϸ�
			start = ++save_start;	//save_start �� ���� �� start ����
			count++;				//�����տ� �ش��ϴ� Ƚ�� ����
			sum = 0;				//sum �ʱ�ȭ
		}
		else if (sum < n) {			//n�� sum���� ũ�ٸ�
			start++;				//start ����
		}
		else if (sum > n) {			//n�� sum���� ������
			start = ++save_start;	//save_start �� ������ start ����
			sum = 0;				//sum �ʱ�ȭ
		}
	}
	cout << count;					//count Ƚ�� ���

	return 0;
}