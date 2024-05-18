#include <iostream>
#include <stack>

using namespace std;

int calc(int x, int y, char op){
	if (op == '+')		return x + y;
	else if (op == '-')	return x - y;
	else if (op == '*')	return x * y;
	else if (op == '/')	return x / y;
	else if (op == '%')	return x % y;
	return 0;
}

int evaluate(string post){
	int result, v1, v2;
	stack<int> s;
	for (char c : post){
		if (c >= '0' && c <= '9')	
		// c is of type string. so to convert it to int we are doing c-'0' since c is char and its value
		// is stored as its ascii. if c is '3' then value of c is 51 and value of '0' is 48 so we get 
		// 51-48=3 . 3 here is of type int. although we could do int(c) but this would also give us its 
		// ascii i.e 51
		s.push(c - '0');	//convert character digit to number digit
		else{
			v1 = s.top();	s.pop();
			v2 = s.top();	s.pop();
			result = calc(v2, v1, c);
			s.push(result);
		}
	}
	return s.top();
}
int main(){
	cout << "2+3*4 = " << evaluate("234*+") << '\n';
	cout << "(2+3)*4 = " << evaluate("23+4*") << '\n';
	cout << "2+3*4/2 = " << evaluate("234*2/+") << '\n';
	cout << "(2+3)*(4-2)/(1+4) = " << evaluate("23+42-*14+/") << '\n';
    return 0;
}