#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

class Info {	//구조체 Info -> num(숫자), pos(위치)
public :
	int num;
	int pos;
};
bool desc(int a, int b) {	//sort에서 내림차순 정렬 함수
	return a > b;
}
int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int n, m, x, y;
	cin >> n;

	queue<Info> q;			//구조체 Info Queue
	Info info;

	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> m >> x;
		int* priority = new int[m+1];	//중요도 배열 선언
		for (int j = 0; j < m; j++) {
			cin >> y;					
			info.num = y;				
			info.pos = j;
			q.push(info);
			priority[j] = y;
		}
		//Info의 숫자, 위치 저장 & Queue에 삽입 & 가중치 저장
		sort(priority, priority + m, desc);
		//가중치 내림차순으로 정렬

		while (!q.empty()) {	//Queue가 빌때 까지
			Info info = q.front();	// info = Queue의 맨 앞 구조체
			if (info.num == priority[count] && info.pos == x) {
				cout << ++count << '\n';
				break;
			}						
			//info의 숫자와 가중치가 같고, info의 위치가 우리가 찾는 위치와 같다면
			//count 선 증가 후 출력 & while문 종료
			else if (info.num == priority[count] && info.pos != x){
				q.push(info);
				q.pop();
				count++;
			}
			//info의 숫자와 가중치와 같고, info의 위치가 우리가 찾는 위치가 아니라면
			//해당 info를 Queue의 맨 뒤에 삽입 후 count증가.
			else {
				q.push(info);
				q.pop();
			}
			//info의 숫자와 가중치가 같지 않으면
			//해당 info를 Queue의 맨 뒤에 삽입 후 count증가.
		}
		while (!q.empty())
			q.pop();
		//while문이 끝나면 Queue가 빌 때 까지 pop
		count = 0;
	}
}