// Laszlo Kazmer
// 512
// Lab6/1
// A háború során 𝑚 különböző helyen kell őrt állni, mindegyik helyről tudjuk, 
// hogy melyik nap kezdetétől melyik nap végéig kell ott szolgálatot teljesítsen egy katona. 
// Állapítsuk meg, hogy elegendő-e 𝑛 darab katona ahhoz, hogy őrt álljunk mind az 𝑚 helyen!
#include<iostream>
using namespace std;

long maxkivalaszt1 ( long n, long a[], long maxi, long eleje, long vege ){
    maxi = a[eleje];
    for ( long i = eleje + 1; i <= vege ;i++ ){
        if ( maxi < a[i] ) maxi = a[i];
    }
    return maxi;
}

void be ( long &n, long &m, long allomasok[], long &e, long &v ){
    cin >> n >> m;
    long x, y;
    for ( long i = 1; i <= m; i++ ){
        cin >> x >> y;
        if ( v < y ) v = y;
        if ( e > x ) e = x;
        for ( long j = x; j <= y; j++ ){
            allomasok[j]++;
        }
    }
}

int main (){
    long n, m, allomasok[10001] = {0}, megoldas, eleje = 10001, vege = 0;
    be(n, m, allomasok, eleje, vege);
    if ( n >= m ){
        cout << "igen";
    }
    else{
    megoldas = maxkivalaszt1(n, allomasok, megoldas, eleje, vege);
    if ( megoldas <= n ) cout << "igen";
    else cout << "nem";
    }
}