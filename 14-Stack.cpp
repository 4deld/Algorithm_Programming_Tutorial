#include<iostream>
#include<stack>
using namespace std;
int main() {
	stack<int> s;
	s.push(7);
	s.push(5);
	s.push(2);
	s.pop();
	s.push(19);
	while (!s.empty()) {
		cout << s.top() << '\n';
		s.pop();
	}
	return 0;
}