#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string s="ab#c";
    string t="ad#c";
    stack <char> ss;
    stack <char> st;
    int r=0;
    int c=0;
    while (r<size(s) && c < size(t)){
        if (s[r]!= '#')
        ss.push(s[r]);
        else
        ss.pop();
        if (t[r] != '#')
        st.push(t[r]);
        else
        st.pop();
        
    }
    
    string new1="";
    string new2="";
    while (! ss.empty()){
        char top=ss.top();
        new1+=top;
        ss.pop();
    }
     while (! st.empty()){
        char top=st.top();
        new2+=top;
        st.pop();
    }
    if (new1==new2)
    cout<<"True";
    return 0;
}
#include<iostream>
#include<stack>
#include<string>
using namespace std;
int main(){
    string s="ab#c";
    string t="ad#c";
    stack <char> ss;
    stack <char> st;
    int r=0;
    int c=0;
    while (r<size(s) && c < size(t)){
        if (s[r]!= '#')
        ss.push(s[r]);
        else
        ss.pop();
        if (t[r] != '#')
        st.push(t[r]);
        else
        st.pop();
        
    }
    
    string new1="";
    string new2="";
    while (! ss.empty()){
        char top=ss.top();
        new1+=top;
        ss.pop();
    }
     while (! st.empty()){
        char top=st.top();
        new2+=top;
        st.pop();
    }
    if (new1==new2)
    cout<<"True";
    return 0;
}