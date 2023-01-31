//Laszlo Kazmer
//512
//Lab2/1
//Ismerjük egy osztály tanulóinak neveit (családnév + keresztnév) és év végi átlagait.
//Állapítsuk meg, hogy egy adott nevű tanuló az első három díjazott között van-e?
#include<iostream>
#include<algorithm>
using namespace std;


bool egyezik_nev ( string csaladnev, string keresztnev, string keres_csaladnev, string keres_keresztnev ){
if ( csaladnev == keres_csaladnev && keresztnev == keres_keresztnev ) return true;
else return false;
}

long megszamlalas ( double x, long n, double a[], long &db ){
    db = 0;
    for ( long i = 1; i <= n; i++ ){
    if ( a[i] > x ) db++;
    }
    return db;
}

void ki ( bool x ){
    if ( x ) cout << "igen";
    else cout << "nem";
}

bool kivalasztas ( long n , string csaladnev[], string keresztnev[], string keres_csaladnev, string keres_keresztnev, long hely, double jegy[] ){
    hely = 1;
    while ( !egyezik_nev( csaladnev[hely], keresztnev[hely], keres_csaladnev, keres_keresztnev ) && hely < n ) 
    {
    hely++;
    }
    if ( !egyezik_nev( csaladnev[hely], keresztnev[hely], keres_csaladnev, keres_keresztnev ) ) return 0;
    long db = 0;
    db = megszamlalas(jegy[hely], n, jegy, db );
    if ( db > 2 ) return 0;
    else return 1;
}



int main(){
    string csaladnev[1001], keresztnev[1001], keres_csaladnev, keres_keresztnev;
    long n, hely=1, k = 1;
    double jegy[101], maxik[5]={0};
    cin >> n;
    for ( long i = 1; i <= n; i++ ) cin >> csaladnev[i] >> keresztnev[i] >> jegy[i];
    cin >> keres_csaladnev >> keres_keresztnev;
    if ( kivalasztas(n, csaladnev, keresztnev, keres_csaladnev, keres_keresztnev, hely, jegy) ) cout << "igen";
    else cout << "nem";
        return 0;
}