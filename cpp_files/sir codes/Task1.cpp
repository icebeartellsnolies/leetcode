#include <iostream>
#include <stack>

using namespace std;

int main(){
	stack <int> s;
	s.push(23);
	s.push(34);
	s.push(56);
	s.push(16);
	while(!s.empty()){
		cout << s.top() << ' ';
		s.pop();
	}
	cout << "\n";
    return 0;
}

