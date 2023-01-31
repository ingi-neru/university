#include<iostream>
using namespace std;

unsigned long meghat_fibo (unsigned long n ){
unsigned long fn = 1, fnn = 1, db = 2;
for ( unsigned long long i = 3; i <= n; i++ ){
fn += fnn;
fnn = fn - fnn;
}
return fn;
}

int main (){
    unsigned long n, fb1 = 1, fb2 = 1, fbminusz = 0, fbplusz = 0, osztando = 1000000007;
    cin >> n;
    cout << meghat_fibo(n) % osztando;
    return 0;
}