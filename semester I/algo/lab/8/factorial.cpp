// Laszlo Kazmer
// 512
// Lab8/1
// Számoljátok ki 𝑛 faktoriálisát a dinamikus programozás módszerével!
#include<iostream>
using namespace std;

long factorial ( long n ){
    long fact[16] = { 1, 1};
    for ( long i = 2; i <= n; i++ ){
        fact[i] = fact[i - 1] * i;
    }
    return fact[n];
}

int main (){
    long n;
    cin >> n;
    cout << factorial(n);
    return 0;
}