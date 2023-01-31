//Laszlo Kazmer
//512
//Lab2/2
//Határozzuk meg egy adott 𝑥 természetes szám legkisebb osztóját, amely nagyobb mint 1!
#include<iostream>
#include<cmath>
using namespace std;

bool oszto ( unsigned long n , unsigned long i ){
    return !( n % i ); 
}

unsigned long dontes3 ( unsigned long n ){
    unsigned long  i = 2;
    while ( i <= sqrt(n) && !oszto(n,i) ) i++;
    if ( i <= sqrt(n) ) return i;
    else return n;
}

int main(){
    unsigned long n;
    cin >> n;
    cout << dontes3( n );
    return 0;
}