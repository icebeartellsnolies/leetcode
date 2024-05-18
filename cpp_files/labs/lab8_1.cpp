#include<iostream>
using namespace std;

void print_elements(int arr[],int len, int size){
    if (len==size){
        return;
    }
    cout << arr[len] << " ";
    print_elements(arr,len+1, size);
    
}

void print_elements(int arr[], int size){
    print_elements(arr, 0, size);
}

int main(){
    const int size =5;
    int array[size]={1,2,3,4,5};
    print_elements(array, size);
}