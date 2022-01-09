#include<bits/stdc++.h>

using namespace std;

/*
    Euclid's GCD Algorithm
    Calcuates GCD of two numbers a and b
    Complexity: Approximately linear with total number of digits
                Can be considered as log2(a)
*/

int gcd(int a, int b) {
    if(b == 0) return a;

    return gcd(b, a%b);
}

/*
    Extended version of Euclid's GCD
    Finds a solution (x, y) for ax + by = g
    where, g = gcd(a, b)
    This can be used to find solutions of
    linear diophantine equations: ax + by = c
*/

int extended_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int g = extended_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1 * (a/b);
    return g;
}

int main() {
    cout<< gcd(15, 20) << "\n";

    int x, y;

    cout<< extended_gcd(15, 20, x, y) << "\n";

    cout<< (15 * x + 20 * y) == gcd(15, 20) << "\n";
    
    return 0;
}