//Laszlo Kazmer
//512
//Lab3/7
//Bontsunk fel egy adott számot 2 hatványainak összegére!
#include<iostream>
using namespace std;
void be ( unsigned long &n ){
    cin >> n;
}

void tombbe_tesz (unsigned long n, unsigned long hatvanyok[], unsigned long &hossz ){
hossz = 0;
while ( n > 0 ){
    hatvanyok[++hossz] = n % 2;
    n /= 2;
}
}

void kiir ( unsigned long hatvanyok[], unsigned long hossz ){
    unsigned long k = 1;
    while ( hatvanyok[k] != 1 ) k++;
    for ( unsigned long i = hossz; i > k; i-- ) if ( hatvanyok[i] )cout << "2^" <<  i - 1 << "+";
    cout << "2^" << k - 1;
}
int main (){
    unsigned long n,hatvanyok[101], hossz = 1;
    be(n);
    
    if ( n <= 1 ) cout << 0;
    else{
    tombbe_tesz(n, hatvanyok, hossz);
    kiir(hatvanyok, hossz);
    }
    return 0;
}