#include<iostream>
#define ull unsigned long long

using namespace std;

const ull mod = 1e9 + 7;

ull catalan ( int n ){
    ull piece = 1, num = 1, denom = 1;
    for ( int i = n + 2; i <= (2 * n); i++ ){
        num = ( num * i ) % mod;
    }

    for ( int i = 2; i <= n; i++ ){
        denom = ( denom * i ) % mod;
    }

    while ( denom * piece % mod != 1 ){
        piece++;
    }
    return ( num * piece ) % mod;
}

int main(){
    int n;
    cin >> n;
    cout << catalan(n);
    return 0;
}