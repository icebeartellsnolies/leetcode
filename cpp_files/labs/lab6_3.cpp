#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <utility>

using namespace std;

int main(){
	srand(time(0));
	// int processes[]={rand()%18 + 2, rand()%18 + 2, rand()%18 + 2, rand()%18 + 2, rand()%18 + 2};
	int processes[]={15,5,13,13,7};
	cout << "Process Times: ";
	for (int t : processes) 
		cout << t << ' ';
	cout << '\n';	
	queue<pair<int, int>> q;
	// queue: class name; <int: datatype of param, int: datatype of param> ; q: name of obj
	for (int i = 0 ; i < 5 ; i++)
		q.push({i, processes[i]});
	int i = 0;
	for ( ; i < 5 ; i++)
		q.push({i, processes[i]});
	int prev = i;
	int total_processes = i;
	int processed_elem = 0;

	while (!q.empty()){
		bool dont_add=true;
		pair<int, int> a = q.front();
		q.pop();
		if (a.second >= 4)	cout << "Process " << a.first << " in PF for 4 seconds\n";
		else				cout << "Process " << a.first << " in PF for " << a.second << " seconds\n";
		if (a.second > 4)	q.push({a.first, a.second - 4});

		if (processed_elem+1 != total_processes){
			pair <int,int> b = q.front();
			q.pop();
			if (b.second >= 4)
			cout << "process "<< b.first << " in PS for 4 seconds \n";
			else
			cout << "process "<< b.first << " in PS for "<< b.second << " seconds \n";
			if (b.second>4){
				q.push({b.first, b.second-4});
			} 		
		}
		
		if (processed_elem+1==total_processes){
			int no_of_input_processes,a,b;
			cout<<"how many processes do u want to add in the system?\n";
			cin>>no_of_input_processes;
			if (no_of_input_processes==1){
				cin>>a;
				cout << "Process " << prev << " time "<< a<< " seconds\n";
				prev++;
				
			}
			else if (no_of_input_processes==2){
				cin>>a;
				cin>>b;	
				cout << "Process " << prev << " time "<< a<< " seconds\n";
				prev++;
				cout << "Process " << prev << " time "<< b<< " seconds\n";
				prev++;
				
			}
			else{
				cout << "No new process" << endl;
				
			}
			// dont_add=true;
			processed_elem = -2;
		}		

		// if (!dont_add)
			processed_elem+=2;
	}
	return 0;
}
