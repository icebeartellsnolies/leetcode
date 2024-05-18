template <typename type>
// we can replace 'typename' with 'class'
class Stack{
	// type: This is a placeholder for the actual data type that the stack will store. It could be
	// int, char, double, or any other valid data type.
	// NOTE : this type is the same as in line 1
		type *val;

		int position, size;
		void resize(){ 
			size = size * 2;
			type *previousVal = val;
			val = new type[size];
			for (int i = 0 ; i < position ; i++)	val[i] = previousVal[i];
			delete []previousVal;
		}
	public:
		// constructor
		Stack(int s = 100){	
			if (s < 0)	throw("Illegal Parameter");
			size = s; // or this -> size = size; had we had size as param instead of s
			position = 0;
			val = new type[size];
		}
		type push(const type& element){ 
		// type& element means that the obj wil be passed as reference else a copy will be made by copy
		// constructor and passed to the func
		// const means that its value wont be changed
			if (position == size)	resize();
			val[position++] = element;
			return element;
		}
		type top() const{
			if (empty())	throw("Illegal Operation");
			return val[position - 1];
		}
		void pop() {
			if (empty())	throw("Illegal Operation");
			position--;
		}
		bool empty() const{
			return (position == 0);
	}
};
int main(){
    Stack <int> st(5);
    // st.pop();
    st.push(12);
    st.push(13);
    st.push(14);
    st.push(15);
    st.push(16);
}
