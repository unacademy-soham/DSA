#include<bits/stdc++.h>

using namespace std;

/*
    Code for Binary Exponentiation
    Calculates (a^b % m) fast
    Complexity: log2(b)
*/

// Recursive

long long fxp(long long a, long long b, long long m) {
    if(b == 0LL) return 1LL;
    if (a >= m) a %= m;
    long long res = fxp(a, b>>1LL, m);
    if (b&1LL) return (((a * res) % m) * res) % m;
    return (res * res) % m; 
}

// Iterative
long long fxp_iterative(long long a, long long b, long long m) {
    long long res = 1LL;
    a %= m;
    while(b > 0LL) {
        if(b&1LL) {
            res = (res * a) % m;
        }
        b >>= 1LL;
        a = (a * a) % m;
    }
    return res;
}

int main() {
    long long mod = (long long)(1e9+7);

    cout << fxp(3LL, 4LL, mod) << "\n";
    cout<< fxp_iterative(3LL, 4LL, mod) << "\n";

    long long res1 = fxp(1000002LL, 1234567891LL, mod);
    long long res2 = fxp_iterative(1000002LL, 1234567891LL, mod);
    
    cout<< res1 << " " << res2 << "\n";

    cout<< (res1 == res2) << "\n";
}