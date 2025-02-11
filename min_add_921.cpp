#include <iostream>
#include <stack>
using namespace std;

int minAddToMakeValid(string s) {
    stack<char> st;
    bool opening = false;
    for (char bracket : s) {  
        if (bracket == '(') {  
            st.push(bracket);
        }
        else if (bracket==')') {
            if (!st.empty() && st.top()=='('){
            st.pop();
            }
            else
            st.push(bracket);
        }
    }

    int count = 0;
    while (!st.empty()) { 
        st.pop();
        count++;
    }
    return count;
}

int main() {
    cout << minAddToMakeValid("()))") << endl;
    // cout << minAddToMakeValid("(((") << endl;
    cout << minAddToMakeValid("((())") << endl;
    return 0;
}
