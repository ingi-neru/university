// Laszlo Kazmer
// 512
// Lab6/1
// Adott egy 𝑛 × 𝑚-es mátrix. Határozzuk meg azt a legnagyobb 𝑛 elemű összeget,
// amelyet úgy kapunk meg, hogy minden elem a mátrix különböző soraiból “származik” és az 𝑖. sorból kiválasztott elem kisebb
// mint az 𝑖 + 1. sorból kiválasztott elem.
#include<iostream>
#include<climits>
using namespace std;

void be( long &n, long &m, long mat[][501] ){
    cin >> n >> m;
    for ( long i = 1; i <= n; i++ ){
        for ( long j = 1; j <= m; j++ ){
            cin >> mat[i][j];
        }
    }
}
long maxosszeg ( long n, long m, long mat[][501] ){
    long osszeg = 0, seged = LONG_MAX;
    long maxi;
    for ( long i = n; i >= 1; i-- ){
        maxi = LONG_MIN;
        for ( long j = 1; j <= m; j++ ){
        if ( mat[i][j] < seged && mat[i][j] > maxi ){
        maxi = mat[i][j];
        }
        } 
        if ( maxi != LONG_MIN ) seged = maxi;
        else return LONG_MIN;
        osszeg += maxi;
}
return osszeg;
}

int main(){
    long n, m, mat[501][501], megoldas;
    be(n, m, mat);
    megoldas = maxosszeg(n, m, mat);
    if ( megoldas != LONG_MIN ) cout << megoldas;
    else cout << "nincs megoldas";

    cout << endl;
    for ( int i = 1; i <= 10; i++ ){
        for ( int j = 1; j <= 10; j++ ){
            if ( i == 3 && j == 8 ) cout << 1 << " ";
            else if ( i == 7 && j == 7 ) cout << 1 << " ";
            else if ( i == 4 && j == 4 ) cout << 1 << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}