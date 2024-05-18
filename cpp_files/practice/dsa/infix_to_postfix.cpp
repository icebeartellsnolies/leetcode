#include <iostream>
using namespace std;
#include <stack>

int precedence(char op){
    if(op=='+' || op=='-') return 1;
    else if (op=='*' || op=='/') return 2;
    return 0;
}
string postfix_production(string infix){
    stack <char> s;
    string postfix;
    for (char character:infix){
        if (character>='0' && character<='9'){
            postfix+=character;
        }
        else if (character=='-' || character=='+' || character=='*' || character=='/'){
            if (s.empty()) s.push(character);
            else {
                if(precedence(character)<precedence(s.top())){
                    while(!s.empty()&&precedence(character)<=precedence(s.top())){
                        postfix+=s.top();
                        s.pop();
                    }
                    s.push(character);
                }
                else{
                    s.push(character);
                }
            }
        }
        else{
            if (character=='(') s.push(character);
            else if(character==')'){
                while(!s.empty() && s.top()!='('){
                postfix+=s.top();
                s.pop();
                }
                if (!s.empty()) s.pop();
            }
        }
    }
    while(!s.empty()){
        postfix+=s.top();
        s.pop();
    }
    
    return postfix;
}
int main(){
    // string str="1+5*2+1";
    string str="((1+3)-2*(4/5))+6";
    cout<<postfix_production(str);
    return 0;
}
