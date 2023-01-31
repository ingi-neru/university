// Laszlo Kazmer
// 512
// Lab6/10
//Az állami kincstárba 𝑛 zsákban hozzák a pénzérméket.
// A raktár főnöke ismeri minden zsák tartalmát (az érmék számát) és át szeretné rendezni minden zsák tartalmát az érmék költöztetésével úgy,
// hogy végül minden zsákban azonos számú érme legyen.
// Írjunk heurisztikus algoritmust, amely segít a főnöknek, hogy, amennyiben ez lehetséges a legkevesebb költöztetéssel érje el a célját!
#include<iostream>
using namespace std;

void be ( long &n, long zsakok[], long maxi, long mini, long &atlag ){
    cin >> n;
    maxi = 0, mini = 1000000000;
    for ( long i = 1; i <= n; i++ ){
        cin >> zsakok[i];
        atlag += zsakok[i];
        if ( zsakok[i] > maxi ) maxi = zsakok[i];
        if ( zsakok[i] < mini ) mini = zsakok[i];
    }
    atlag /= n;
}

void lepesek_szama ( long n, long zsakok[], long atlag,  long &darab ){
    for ( long i = 1; i < n; i++ ){
        bool t = true;
        for ( long j = 1; j <= n && t; i++ ){
            if ( zsakok[i] + zsakok[j] / 2 == atlag && zsakok[i] != atlag ){
            zsakok[i] = atlag;
            zsakok[j] = atlag;
            t = false;
            }
        }
    }
}

int main(){
    long n, zsakok[1001], atlag = 0;
    be(n, zsakok, maxi, mini, atlag);
    lepesek_szama(n, zsakok, atlag, darab);
    cout << darab;
    return 0;
}