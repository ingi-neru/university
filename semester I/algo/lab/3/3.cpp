//Laszlo Kazmer
//512
//Lab3/3
//Írjunk algoritmust, amely megadja a Fibonacci-sorozat egy adott 𝑥 szám- nál kisebb elemeinek számát! 
//A Fibonacci-sorozat nulladik elemét nem kell figyelembe venni.
#include<iostream>
#include<climits>
using namespace std;
unsigned long long kisebb_fibo ( unsigned long long n){
    unsigned long long fn = 1, fnn = 1, db = 1; 
    while ( fn < n ){
    fn += fnn;
    fnn = fn - fnn;
    db++;
    }
    return db;
}

void be ( unsigned long long &n ){
    cin >> n;
}

int main (){
    unsigned long long n, db = 0;
    be(n);
    if ( n == 0 || n == 1 ) cout << 0 << " darab kisebb elem van a Fibonacci-sorozatban, mint " << n;
    else{
    if ( n < ULLONG_MAX ){
    db = kisebb_fibo(n);
    cout << db << " darab kisebb elem van a Fibonacci-sorozatban, mint " << n;
    }
    else cout << 93 << " darab kisebb elem van a Fibonacci-sorozatban, mint " << n;
    }
    return 0;
}