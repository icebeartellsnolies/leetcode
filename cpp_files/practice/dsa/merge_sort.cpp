#include <iostream>
#include <vector>
using namespace std;

vector<int> &mergelists(vector<int> &a, int left, int mid, int right) {
    int n1 = mid - left + 1; 
    int n2 = right - mid;    
    int k = left;
    vector<int> L(n1);
    vector<int> R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; j++) {
        R[j] = a[mid + 1 + j];
    }

    int i = 0, j = 0;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    return a;
}

void mergesort(vector<int> &a, int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    mergesort(a, left, mid);
    mergesort(a, mid + 1, right);
    mergelists(a, left, mid, right);  
}

int main() {
    vector<int> a = {2, 1, 3, 2, 5, 4, 2};
    mergesort(a, 0, a.size() - 1); 
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << " ";
    }
    return 0;
}