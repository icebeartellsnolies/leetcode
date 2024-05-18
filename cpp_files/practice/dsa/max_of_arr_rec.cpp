#include<iostream>
using namespace std;

int max_element(int arr[],int n){
    int x;
    if(n==1) return arr[0];
    else{
        x=max_element(arr,n-1);
        if (arr[n-1]>x)
            return arr[n-1];
        else
            return x;
    }
}

int max_element2(int arr[], int n){
    if (n==1) 
        return arr[0];
    else
        return max(arr[n-1],max_element2(arr, n-1));
}
int main(){
    int arr[5]={1,7,3,4,5};
    // cout<< max_element(arr,5);
    cout<< max_element2(arr,5);
    return 0;
}