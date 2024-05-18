#include <iostream>
using namespace std;
#include <iomanip>
int main()
{
    int marks[30];
    int roll_no[30];
    for (int i = 0; i < 30; i++) {
        roll_no[i] = i + 1;
        marks[i] = rand() % 100;
        cout << marks[i] << " ";

    }
    cout << endl;
    /*int indices_to_ignore[5];*/
    int random_nos = 0;
    while (random_nos<5) {
        int to_ignore_index = rand() % 30;
        if (roll_no[to_ignore_index] != -1) {
            roll_no[to_ignore_index] = -1;
           /* indices_to_ignore[random_nos] = to_ignore_index;*/
            random_nos++;
        }
    }

    for (int i = 0; i < 30; i++) {
      
       
        cout << roll_no[i] << " ";

    }

    int updated_marks[25];
    int updated_roll_nos[25];
    int n = 0;
    cout << "\n";
    cout << "Roll No   Marks";
    for (int i = 0; i < 30; i++) {
        if (roll_no[i] != -1) {
            cout << "\n";
            cout << setw(7) << roll_no[i];
            cout << setw(7) << marks[i];
            updated_marks[n] = marks[i];
            updated_roll_nos[n] = roll_no[i];
            n++;
        }
    }
    cout << "\n";
    for (int i = 0; i < 25; i++) {
        cout << setw(5) << updated_roll_nos[i];

    }
    cout << "\n";
    for (int i = 0; i < 25; i++) {
        cout << setw(5) << updated_marks[i];

    }
    return 0;
}