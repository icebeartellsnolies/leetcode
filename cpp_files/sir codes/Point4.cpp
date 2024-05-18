#include <iostream>
#include <cmath>
	
using namespace std;

class Point{
		int x, y;
	public:
		Point(){
			x = y = 0;
		}
		Point(int x, int y){
			set(x, y);
		}
		Point(Point &p){	
			cout << "Copy constructor called\n";
			x = p.x;
			y = p.y; 
		}
		void set(int x1, int y1){
			if (x1 < 0)		x1 = 0;
			if (y1 < 0)		y1 = 0;
			x = x1;
			y = y1;
		}
		bool isEqual(const Point p){	
		//to check call to copy constructor
		//bool isEqual(const Point& p){
			return x == p.x && y == p.y;
		}
		float distance(const Point &p){
			return sqrt(((x - p.x) * (x - p.x)) + ((y - p.y) * (y - p.y)));
		}
		void show(){
			cout << "X: " << x << "\tY: " << y << '\n';
		}
};
int main(){
	Point p1(4, 1), p2(3, 7);
	Point p3 = p1;
	if (p1.isEqual(p2))	
		cout << "P1 and P2 are equal\n";
	else
		cout << "P1 and P2 are not equal\n";
	if (p1.isEqual(p3))	
		cout << "P1 and P3 are equal\n";
	else
		cout << "P1 and P3 are not equal\n";
	cout << "Distance p1 & p2 : " << p1.distance(p2) << '\n';
	return 0;
}
