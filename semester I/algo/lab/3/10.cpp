//Laszlo Kazmer
//512
//Lab3/10
//Határozzuk meg, hogy melyik számjegyet hányszor kell leírnunk, ha egyenként minden természetes számot le akarunk írni az [𝑥, 𝑦] intervallumból!
#include<iostream>
#include<cmath>
using namespace std;

long long int szamjegyek ( long long int n ){
    long long int db = 0;
    while ( n > 0 ){
        db++;
        n /= 10;
    }
    return db;
}

long long nullak ( long long szam, long long elofordulasi[], long long szamj ){
szamj = szamjegyek(szam);
long long osszeg = 0,jelenlegi = szam / ( pow ( 10, szamj ) / 100 );
for ( long i = 1; i <= 9; i++ ) osszeg += elofordulasi[i];
cout << osszeg << endl;
return ( szamj + 1 ) * ( szam % 10 + 1 + jelenlegi * pow ( 10, szamj ) ) - osszeg;
}


long long int visszaterit_szama ( long long int i, long long int &szam, long long int &k, long long int &jelenlegi ){
long long int hatv = pow(10, k);
szam %= hatv, jelenlegi = szam / ( hatv / 10 ), k--;
if ( szam < 10 ){
    if ( jelenlegi >= i ) return 1;
    else return 0;
}
else if ( jelenlegi < i && jelenlegi != 0 ) {
    //cout << jelenlegi * k * pow(10, k - 1) << endl;
    return jelenlegi * k * pow(10, k - 1) + visszaterit_szama(i, szam, k, jelenlegi);
}
else if ( jelenlegi == i ) {
    long long int sz = szam % (hatv / 10 );
    //cout << jelenlegi * k * pow(10, k - 1) + sz + 1 << endl;
    return jelenlegi * k * pow(10, k - 1) + sz + 1 + visszaterit_szama(i, szam, k, jelenlegi);
}

else if ( jelenlegi > i ){
    //cout << ( jelenlegi * k + 10 ) * pow(10, k - 1) << endl;
    return ( ((jelenlegi * k) + 10) * pow(10, k - 1) ) + visszaterit_szama(i,szam, k, jelenlegi) ;
}
else return visszaterit_szama(i,szam, k, jelenlegi) ;
}

void felepit_tomb ( long long int elofordulasi[], long long int szam, long long int elojel ){
for ( long long int i = 0; i <= 9; i++ ){
    long long int seged = szam, k = szamjegyek(seged), jelenlegi = seged / ( k / 100 );
    elofordulasi[i] += elojel * visszaterit_szama(i, seged, k, jelenlegi);
}
}
int main(){
    long long e = 1, v = 1, elofordulasi[10] = {0}, szam = 314159, k = szamjegyek(szam), jelenlegi = szam / ( k / 100 ), b = szam % 10;
    bool t = false;
    cin >> e >> v;
    felepit_tomb(elofordulasi, v, 1);
    elofordulasi[0] = nullak(v, elofordulasi, k);
    felepit_tomb(elofordulasi, e, -1);
    elofordulasi[0] -= nullak(e, elofordulasi, k);
    for ( long long int i = 0; i <= 9; i++ ) cout << elofordulasi[i] << " ";
    return 0;
}