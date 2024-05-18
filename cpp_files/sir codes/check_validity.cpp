#include "stack.cpp"
#include <iostream>
#include <string>

using namespace std;

bool isValid(const string& s){
	Stack<char> st;
	char ch;
	for (char c : s){
		if (c == '[' || c == '{' || c == '(' || c == '<')	st.push(c);
		else if (c == ']' || c == '}' || c == ')' || c == '>'){
			if (st.empty())	return false;
			if (c == ']'	&& st.top() != '[')		return false;
			if (c == '}'	&& st.top() != '{')		return false;
			if (c == ')'	&& st.top() != '(')		return false;
			if (c == '>'	&& st.top() != '<')		return false;
			st.pop();
		}
	}
	if (st.empty())	return true;
	return false;
}

int main(){
	string samples[] ={"[{(<>)({}[])}]", "<({[[]()]})>", "[{(<{[]}>)}]", "{[(<)>]}", "[{([]}"};
	for (string s : samples)
		if (isValid(s))		cout << s << " is valid\n";
		else				cout << s << " is invalid\n";

	string samples1[3];
	samples1[0] = "#include <iostream> int main() { int x = 10; } return 0;}";
	samples1[1] ="template <typename T> class Stack { public: Stack() { top = -1; } bool push(T item) {  { stack[++top] = item; return true; } return false; } T pop() { return stack[top--]; return T(); } private: static const int MAX = 100; T stack[MAX]; int top;}; int main() { Stack<int> myStack; myStack.push(5);   return 0; }";
	samples1[2] ="#include <iostream> int main() { cout << \"Hello, World!\" << endl; if (true) { cout << \"This will run\";  // Missing closing bracket return 0;}";
	for (string s : samples1)
		if (isValid(s))	cout << s << " is valid\n";
		else				cout << s << " is invalid\n";	
	return 0;
}
