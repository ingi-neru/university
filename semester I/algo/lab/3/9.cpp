//Laszlo Kazmer
//512
//Lab3/9
//Keressük meg adott számmal bezárólag a legtöbb osztójú természetes számot!
#include<iostream>
using namespace std;

long long hatvanyok_szorzata ( long long n ){
long long db = 0, osztok_szama = 1, m = n;
while ( m % 2 == 0 ) m /= 2, db++;
osztok_szama *= (db + 1);
for (long long oszto = 3; oszto * oszto <= m; oszto += 2) {
    db = 0;
    while (m % oszto == 0) {
        db++;
        m /= oszto;
    }
    osztok_szama *= (db + 1);    
}
if ( m > 2 ) osztok_szama *= 2;
if ( osztok_szama == 1 ) osztok_szama--;
return osztok_szama;

}
int main(){
    long long szam, valodi_osztok = 1, max_osztok = 0, max_szam = 1;
    cin >> szam;
    for ( long long i = 1; i <= szam && i <= 720720; i++ ) {
    if ( i < 210 || (( i % 2 == 0 ) && ( i % 3 == 0 ) && ( i % 5 == 0 ) && ( i % 7 == 0 ) ))valodi_osztok = hatvanyok_szorzata(i);
    if ( valodi_osztok > max_osztok ) max_osztok = valodi_osztok, max_szam = i;
    }
    if ( szam == 2 ) max_szam = 2;
    if ( max_osztok > 1 ) max_osztok -= 2;
    cout << max_szam << " " << max_osztok;
    return 0;
}