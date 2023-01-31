//Laszlo Kazmer
//512
//Lab3/2
//Írjuk ki 𝑛 darab természetes szám legnagyobb közös osztóját!

#include<iostream>
using namespace std;

unsigned long lnko(unsigned long a, unsigned long b) {
   if (b == 0) return a;
   return lnko (b, a % b);
}

void be ( unsigned long &n, unsigned long a[] ){
    cin >> n;
    for ( unsigned long i = 1; i <= n; i++ ) cin >> a[i];
}

unsigned long osszes_lnko ( unsigned long n, unsigned long a[], unsigned long eredmeny ){
    eredmeny = a[1];
    for ( unsigned long i = 1; i < n; i++ ) eredmeny = lnko( eredmeny, a[i] );
    return eredmeny;
}
int main(){
    unsigned long n, a[100001], ossz_lnko = 1;
    be(n, a);
    ossz_lnko = osszes_lnko(n, a, ossz_lnko);
    cout << ossz_lnko;
    return 0;
}