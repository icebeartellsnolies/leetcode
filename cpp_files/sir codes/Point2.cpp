#include <iostream>
	
using namespace std;

class Point{
		int x, y;
	public:
		Point(int x){
			set(x, x);
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
};
int main(){
	//Point p1;			//uncomment to check error, default constructor exists no more
	Point p2(3);
	//Point p3(4, 7);	//uncomment to check error, only one parameter constructor available
	p2.show();
	p2.set(-5, 3);
	p2.show();
	return 0;
}
