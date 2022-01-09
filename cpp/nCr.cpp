#include<bits/stdc++.h>
#define int long long
using namespace std;

/*
    Problem: https://www.spoj.com/problems/KOPC12B/

    Calculate nCr % m
    Uses Fermat's little theorem

    Formula:
        nCr = n!/((n-r)! * r!)
        nCr % mod = (n! % mod) * (modinverse((n-r)!) * modinverse(r!)) % mod  
*/


const int N = (int)(5e6+5);
const int MOD = (int)(1e9+7);

int fact[N]; // Stores n!
int fact_inv[N]; // Stores Modinverse(n!)


int fxp(int a, int b) {
    int res = 1LL;
    while(b > 0) {
        if(b&1LL) {
            res = (res * a) % MOD;
        }
        b >>= 1LL;
        a = (a * a) % MOD; 
    }
    return res;
}

int nCr(int n, int r) {
    return (((fact[n] * fact_inv[n-r]) % MOD) * fact_inv[r]) % MOD;
}

void precompute() {
    fact[0] = 1;
    fact_inv[0] = 1;

    for(int i=1; i<N; i++) {
        fact[i] = (i * fact[i-1]) % MOD;
        fact_inv[i] = fxp(fact[i], MOD-2);
    }
}

int solve(int n) {
    /*
        For a given n the ans is:
        (n * (2nCn)) / 2 -> Deduce this formula :)
    */
    int ans = nCr(2*n, n);
    ans = (ans * n) % MOD;
    ans = (ans * fxp(2LL, MOD-2)) % MOD;
    return ans;
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    precompute();

    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        cout<< solve(n) <<"\n";
    } 

}


