#include <iostream>
using namespace std;

// Function to calculate GCD using Euclid's algorithm
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to calculate LCM using the formula: LCM(a, b) = (a * b) / GCD(a, b)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int N, M;
    
    // Input values for N and M
    cout << "Enter two integers (N and M): ";
    cin >> N >> M;

    // Calculate and output the LCM
    int result = lcm(N, M);
    cout << "The Least Common Multiple of " << N << " and " << M << " is: " << result << endl;

    return 0;
}
