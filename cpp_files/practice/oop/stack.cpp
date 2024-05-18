#include <iostream>
using namespace std;
#include <stdexcept>
// template <class t>
class stack{
    int *stacked;
    int max_size, position, size;
    public:
        stack(int max_size=100){
            this ->max_size= max_size;
            stacked = new int[max_size];
            position = -1;
            size = 0;
        }
        void push (int element){
            if (size<0) throw runtime_error("illegal operation");
            else if (size<max_size){
                stacked[position] = element;
                if (position==-1)
                    position = 0;
                else
                    position++;
                size++;}
            else
                throw runtime_error("stack already full, can't add anymore elements");
            // return element;
        }
        void pop(){
            if (size==0) throw runtime_error("stack empty");
            position--;
            size--;
        }
        int top(){
            return stacked[position];
        }
        bool is_empty(){
            return size==0;
        }
        bool is_full(){
            return position == size-1;
        }
        int get_size(){
            return size;
        }
};
int main(){
    stack st(5);
    // st.pop();
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    st.push(16);
    // st.push(12);
    // st.top();
    // st.pop();
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;
    // st.pop();
    // cout << st.top() << endl;
    // st.pop();

}