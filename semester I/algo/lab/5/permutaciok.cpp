// Laszlo Kazmer
// 512
// Lab5/1
// Generáljunk minden lehetséges sorozatot, amelynek elemei a 0, 1, 2 halmazból vannak, és a 0 𝑚-szer, az 1 𝑝-szer és a 2 𝑞-szor fordul elő.

#include<iostream>
using namespace std;

bool folytat ( long long i[], long long k, long long darab[] ){
    long long db = 0;
    for ( long long j = 1; j < k; j++ ){
        if ( i[k] == i[j] ) db++;
    }
    if ( db >= darab[i[k]] ) return false;
    else return true;
}

void permutaciok ( long long ossz, long long i[], long long k, long long darab[] ){
    if ( k == ossz + 1 ) {
        for ( long long j = 1; j <= ossz; j++ ) cout << i[j] << " ";
        cout << endl;
    }
    else{
        for ( i[k] = 0; i[k] <= 2; i[k]++ ){
            if ( folytat(i, k, darab) ) permutaciok(ossz, i, k + 1, darab);
        }
    }
}

int main(){
    long long i[13], k = 1, darab[13], ossz = 0;
    for ( long long i = 0; i <= 2; i++ ) cin >> darab[i], ossz += darab[i];
    permutaciok (ossz, i, k, darab);
    return 0;
} 