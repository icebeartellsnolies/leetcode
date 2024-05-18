#include <iostream>
	
using namespace std;

class Point{
		int x, y;
	public:
		// No constructor, no destructor, no copy constructor but everything is working because of
		// default objects
		void setValues(int x1, int y1){
			x = x1, y = y1;
		}
		void show() const{
			cout << "X: " << x << "\tY: " << y << '\n';
		}
};
int main(){
	Point p1, p2;
	cout << "P1: ";	 p1.show();
	cout << "P2: ";	 p2.show();
	p1.setValues(3, 7);
	p2.setValues(4, 1);
	cout << "P1: ";	 p1.show();
	cout << "P2: ";	 p2.show();
	Point p3 = p1;              // Call to copy constructor
	cout << "P3: ";	 p3.show();
	return 0;
}
