#include <iostream>
#include <algorithm>

using namespace std;

// Function to calculate the greatest common divisor (GCD)
int gcd(int a, int b) {
    return (b == 0) ? a : gcd(b, a % b);
}

// Function to process each operation
void processOperation(int N1, int D1, char op, int N2, int D2) {
    int resultN, resultD;

    // Perform the operation based on the operator
    switch (op) {
        case '+':
            resultN = (N1 * D2) + (N2 * D1);
            resultD = D1 * D2;
            break;
        case '-':
            resultN = (N1 * D2) - (N2 * D1);
            resultD = D1 * D2;
            break;
        case '*':
            resultN = N1 * N2;
            resultD = D1 * D2;
            break;
        case '/':
            resultN = N1 * D2;
            resultD = N2 * D1;
            break;
        default:
            return; // Invalid operation
    }

    // Ensure denominator is always positive
    if (resultD < 0) {
        resultN = -resultN;
        resultD = -resultD;
    }

    // Compute the simplified fraction
    int gcdValue = gcd(abs(resultN), abs(resultD));
    int simplifiedN = resultN / gcdValue;
    int simplifiedD = resultD / gcdValue;

    // Print the original fraction and its simplified form
    cout << resultN << "/" << resultD << " = " << simplifiedN << "/" << simplifiedD << endl;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        int N1, D1, N2, D2;
        char slash1, slash2, op;

        // Read input correctly
        cin >> N1 >> slash1 >> D1 >> op >> N2 >> slash2 >> D2;

        // Ensure slashes are correct
        if (slash1 == '/' && slash2 == '/') {
            processOperation(N1, D1, op, N2, D2);
        }
    }

    return 0;
}
