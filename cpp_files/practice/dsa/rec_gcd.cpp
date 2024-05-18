
#include <iostream>
using namespace std;
// Function to calculate the greatest common divisor (GCD) of two numbers
int gcd(int x, int y) {
  // Base case: if either number is 0, return the other number as the GCD
  if (x == 0)
    return y;
  if (y == 0)
    return x;

  // Recursively find the GCD by calling the function with (y, x % y)
  return gcd(y, x%y);
}
int main(){
    cout << gcd(5,10);
    return 0;
}