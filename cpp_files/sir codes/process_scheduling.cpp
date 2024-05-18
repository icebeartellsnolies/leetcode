#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>

using namespace std;

int main(){
	srand(time(0));
	int processes[]={rand()%18 + 2, rand()%18 + 2, rand()%18 + 2, rand()%18 + 2, rand()%18 + 2};
	cout << "Process Times: ";
	for (int t : processes) 
		cout << t << ' ';
	cout << '\n';	
	queue<pair<int, int>> q;
	// queue: class name; <int: datatype of param, int: datatype of param> ; q: name of obj
	for (int i = 0 ; i < 5 ; i++)
		q.push({i, processes[i]});
	while (!q.empty()){
		pair<int, int> p = q.front();
		q.pop();
		if (p.second >= 4)	cout << "Process " << p.first << " in processor for 4 seconds\n";
		else				cout << "Process " << p.first << " in processor for " << p.second << " seconds\n";
		if (p.second > 4)	q.push({p.first, p.second - 4});
	}
	return 0;
}
