// Laszlo Kazmer
// 512
// Lab5/3
// Adva van egy 𝑛 darab egész számot tartalmazó sorozat. 
// Helyezzünk az adott számok közé 𝑛 − 1 aritmetikai műveleti jelet a (+, −, *, /) halmazból, úgy, hogy a kifejezés értéke legyen egyenlő egy adott 𝑥 számmal! 
// A kifejezés értéke minden lépésben legyen egész szám! 
// A műveleteket nem a matematikából ismert operátorprecedencia szerint végezzük, hanem megjelenésük sorrendjében.
#include<iostream>
using namespace std;

bool folytat (long long n, long long i[], long long k, long long szamok[], long long eredmeny, long long &meg ){
    long long e = szamok[1];
    for ( long long j = 1; j <= k; j++ ){
        if ( i[j] == 1 ) e += szamok[j + 1];
        if ( i[j] == 2 ) e -= szamok[j + 1];
        if ( i[j] == 3 ) e *= szamok[j + 1];
        if ( i[j] == 4 ){
        if ( szamok[j + 1] == 0 || e % szamok[j + 1] != 0 ) return false;
        e = e / szamok[j + 1];
        }
    }
    if ( k == n - 1 && ( e != eredmeny ) ) return false;
    else {
        if ( k == n - 1 ) meg++;
        return true;
    }
}

void kiir ( long long n, long long szamok[], long long i[], long long eredmeny ){
    cout << eredmeny << "=" << szamok[1];
    for ( long long j = 1; j < n; j++ ){
        if ( i[j] == 1 ) cout << "+";
        if ( i[j] == 2 ) cout << "-";
        if ( i[j] == 3 ) cout << "*";
        if ( i[j] == 4 ) cout << "/";
        cout << szamok[j + 1];
    }
    cout << endl;
}

void permutaciok ( long long n, long long i[], long long k, long long szamok[], long long &eredmeny, long long &meg ){
    if ( k == n ) {
    kiir(n, szamok, i, eredmeny);
    }
    else{
        for ( i[k] = 1; i[k] <= 4; i[k]++ ){
            if ( folytat(n, i, k, szamok, eredmeny, meg) ) permutaciok(n, i, k + 1, szamok, eredmeny, meg);
        }
    }
}

int main(){
    long long n, i[11], k = 1, szamok[13], ossz = 0, muveletek[11], meg = 0;
    long long eredmeny;
    cin >> n;
    for ( long long j = 1; j <= n; j++ ) cin >> szamok[j];
    cin >> eredmeny;
    permutaciok(n, i, k, szamok, eredmeny, meg);
    if ( meg == 0 ) cout << -1; 
    return 0;
}