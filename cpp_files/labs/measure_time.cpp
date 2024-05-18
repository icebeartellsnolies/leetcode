#include <iostream>
#include <ctime>

using namespace std;
int main() {
    clock_t start = std::clock();
    for (int i = 1; i <= 100000; i++)
        std::cout << i << " ";
    clock_t end = std::clock();
    double duration = 1000.0 * (end - start) / CLOCKS_PER_SEC;
    cout << "\nTime taken to print numbers: " << duration << " milliseconds\n";
    return 0;
}