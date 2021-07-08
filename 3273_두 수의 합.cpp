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
	int count = 0;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());

	cin >> m;
	while (start < end) {
		if (v[start] + v[end] < m)
			start++;
		else if (v[start] + v[end] == m) {
			count++;
			end--;
		}
		else
			end--;
	}
	cout << count;


	return 0;
}
