#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Info {	//����ü Info -> num(����), pos(��ġ)
public :
	int num;
	int pos;
};
bool desc(int a, int b) {	//sort���� �������� ���� �Լ�
	return a > b;
}
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, x, y;
	cin >> n;

	queue<Info> q;			//����ü Info Queue
	Info info;

	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> m >> x;
		int* priority = new int[m+1];	//�߿䵵 �迭 ����
		for (int j = 0; j < m; j++) {
			cin >> y;					
			info.num = y;				
			info.pos = j;
			q.push(info);
			priority[j] = y;
		}
		//Info�� ����, ��ġ ���� & Queue�� ���� & ����ġ ����
		sort(priority, priority + m, desc);
		//����ġ ������������ ����

		while (!q.empty()) {	//Queue�� ���� ����
			Info info = q.front();	// info = Queue�� �� �� ����ü
			if (info.num == priority[count] && info.pos == x) {
				cout << ++count << '\n';
				break;
			}						
			//info�� ���ڿ� ����ġ�� ����, info�� ��ġ�� �츮�� ã�� ��ġ�� ���ٸ�
			//count �� ���� �� ��� & while�� ����
			else if (info.num == priority[count] && info.pos != x){
				q.push(info);
				q.pop();
				count++;
			}
			//info�� ���ڿ� ����ġ�� ����, info�� ��ġ�� �츮�� ã�� ��ġ�� �ƴ϶��
			//�ش� info�� Queue�� �� �ڿ� ���� �� count����.
			else {
				q.push(info);
				q.pop();
			}
			//info�� ���ڿ� ����ġ�� ���� ������
			//�ش� info�� Queue�� �� �ڿ� ���� �� count����.
		}
		while (!q.empty())
			q.pop();
		//while���� ������ Queue�� �� �� ���� pop
		count = 0;
	}
}