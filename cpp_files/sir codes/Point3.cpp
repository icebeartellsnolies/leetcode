#include <iostream>
	
using namespace std;

class Point{
		int x, y;
	public:
		Point(){
			cout << "Non-parameterized constructor called\n";
			x = y = 0;
		}
		Point(int x, int y){
			cout << "Parameterized constructor called\n";
			set(x, y);
		}
		void set(int x1, int y1){
			if (x1 < 0)		x1 = 0;
			if (y1 < 0)		y1 = 0;
			x = x1;
			y = y1;
		}
		void show(){
			cout << "X: " << x << "\tY: " << y << '\n';
		}
		~Point(){
			cout << "destructor called\n";
		}
};
void checkDestructorCalling2(){
	Point p;
	cout << "End of function 2: \n";
}
void checkDestructorCalling1(){
	checkDestructorCalling2();
	Point p;
	cout << "End of function 1: \n";
}
int main(){
	Point p2(3, 7);
	checkDestructorCalling1();
	cout << "End of main: \n";
	return 0;
}
