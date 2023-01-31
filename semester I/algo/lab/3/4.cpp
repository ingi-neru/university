//Laszlo Kazmer
//512
//Lab3/4
//Írjunk algoritmust, amely egy adott 𝑥 páros számot felír két különböző prímszám összegeként (Goldbach-sejtés).


#include<iostream>
#include<cmath>
using namespace std;
void be ( unsigned long &n ){
    cin >> n;
}

bool primszam ( unsigned long n ){
    unsigned long i = 2;
    while ( i <= sqrt(n) ){
        if ( n % i == 0 ) return 0;
        i += 2;
    }
    return 1;
}

void megkeres_primosszeg ( unsigned long n ){
unsigned long index = 3;
bool t = false;
while ( index <= n / 2 && !t ){
    if ( primszam(index) && primszam(n - index) ) cout << n << " = " << index << " + " << n-index, t = true; 
    index++;
}
}
int main (){
    unsigned long n;
    be(n);
    megkeres_primosszeg(n);
    return 0;
}