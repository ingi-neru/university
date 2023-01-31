// Laszlo Kazmer
// 512
// Lab6/5
#include<iostream>
using namespace std;

void be ( long &n, long cipok[], long &ures, long &rendben ){
    cin >> n;
    for ( long i = 1; i <= n + 1; i++ ) {
        cin >> cipok[i];
        if ( cipok[i] == 0 ) ures = i;
        if ( cipok[i] == i ) rendben++;
    }
}

long keres ( long n, long cipok[], long keresett ){
    for( long i = 1; i <= n + 1; i++ ) {
        if ( cipok[i] == keresett) {
        return i;
        }
    }
    return 0;
}

long keresNemRendben ( long n, long cipok[] ){
    for( long i = 1; i <= n + 1; i++ ){
        if ( i != cipok[i] ) return i;
    }
    return 0;
}

long rendez ( long n, long cipok[], long ures, long rendben ){
    long megoldas = 0;
    while ( rendben != n ){
        if ( ures == n + 1){
            long keresett = keresNemRendben(n, cipok);
            cipok[ures] = cipok[keresett];
            ures = keresett;
            megoldas++;
        } 
        else{
            long hely = keres(n, cipok, ures);
            cipok[ures] = ures;
            cipok[hely] = 0;
            ures = hely;
            rendben++;
            megoldas++;
        }
    }
    return megoldas;
}

int main(){
    long n, cipok[10001], ures = 0, rendben = 0;
    be(n, cipok, ures, rendben);
    cout << rendez(n, cipok, ures, rendben);
    return 0;
}