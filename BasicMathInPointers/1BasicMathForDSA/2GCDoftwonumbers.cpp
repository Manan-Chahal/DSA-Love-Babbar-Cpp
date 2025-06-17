#include <iostream>
using namespace std;

// Function to calculate GCD using subtraction-based Euclidean algorithm
int gcd(int A, int B)
{
    if (A == 0)
        return B;
    if (B == 0)
        return A;

    // Keep subtracting the smaller number from the larger one
    while (A > 0 && B > 0)
    {
        if (A > B)
            A = A - B;
        else
            B = B - A;
    }

    // Return the non-zero value (since one will become 0)
    return A == 0 ? B : A;
}

int main()
{
    int A, B;
    
    // Taking input from user
    cout << "Enter two integers to find their GCD: ";
    cin >> A >> B;

    // Calling the GCD function
    int result = gcd(A, B);

    // Printing the result
    cout << "The GCD of " << A << " and " << B << " is: " << result << endl;

    return 0;
}
