#include <iostream>
#include <fstream>

using namespace std;

int main(){  
	ifstream input("data.txt");
	ofstream output("data_modified.txt");
	int i, j , listsCount, elementsCount, *elements, sum, average;
	input >> listsCount;
	output << listsCount << '\n';
	for (i = 0 ; i < listsCount ; i++){
		input >> elementsCount;
		output << elementsCount << '\n';
		elements = new int[elementsCount];
		sum = 0;
		for (j = 0 ; j < elementsCount ; j++){
			input >> elements[j];
			sum += elements[j];
		}
		average = sum / elementsCount;
		for (j = 0 ; j < elementsCount ; j++)
			output << elements[j] - average << ' ';
		output << '\n';
		delete []elements;		
	}
	input.close();
	output.close();
	return 0;
}