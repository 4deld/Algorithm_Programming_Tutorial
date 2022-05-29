#include<iostream>
#include<queue>

using namespace std;

int main() {
	queue<int> q;
	q.push(4);
	q.push(7);
	q.push(45);
	q.push(14);
	q.push(866);
	q.pop();
	while (!q.empty()) {
		cout << q.front() << '\n';
		q.pop();
	}
	return 0;
}