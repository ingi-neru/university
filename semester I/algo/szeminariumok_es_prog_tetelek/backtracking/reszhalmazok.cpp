#include<iostream>
using namespace std;

void reszhalmazok ( long long v[], long long k, long long n ){
    for ( long long j = v[k - 1] + 1; j <= n; j++ ){
        v[k] = j;
        for ( long long i = 1; i <= k; i++ ) cout << v[i] << " ";
        cout << endl;
        reszhalmazok(v, k + 1, n);
    }
}

int main(){
    long long v[11] = { -1, 1, 2, 3 }, k = 1, n = 3;
    v[0] = 0;
    reszhalmazok(v, k, n);
    return 0;
}