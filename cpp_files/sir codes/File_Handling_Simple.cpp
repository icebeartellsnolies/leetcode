#include <iostream>
#include <fstream>

using namespace std;

int main(){  
	cout << "HELO\n";
	ifstream file("data.txt");
	int i, j , listsCount, elementsCount, element, sum;
	file >> listsCount;
	for (i = 0 ; i < listsCount ; i++){
		file >> elementsCount;
		sum = 0;
		for (j = 0 ; j < elementsCount ; j++){
			file >> element;
			sum += element;
		}
		cout << "Average: " << sum / (float)elementsCount << '\n';
	}
	file.close();
	return 0;
}