#include<iostream>
using namespace std;

void be ( long long &n, long long kitevok[], long long &x ){
    cin >> n;
    for ( long long i = 1; i <= n+1; i++ ){
        cin >> kitevok[i];
    }
    cin >> x;
}

long long rekurziv_polinom (long long elso_hatv, long long x, long long tomb[], long long n, long long i ){
if ( i == 1 ){
    return x * tomb[i];
}
else if ( i == n + 1 ) return tomb[i] + rekurziv_polinom(elso_hatv, x, tomb, n, i - 1);
else return x * tomb[i] + rekurziv_polinom(elso_hatv, x * elso_hatv, tomb, n, i - 1);
}

int main(){
    long long n, kitevok[10001], x;
    be(n, kitevok, x);
    long long elso_hatv = x;
    cout << rekurziv_polinom(elso_hatv, x, kitevok,n , n + 1);
    return 0;
}