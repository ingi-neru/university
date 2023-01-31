//Laszlo Kazmer
//512
//Lab4/1
//Rendezzünk egy 𝑛 elemű tömböt beszúró rendezéssel!
#include<iostream>
using namespace std;

void StableCountsort ( long long n, long long a[], long long k ){
    long long darab[1000001], b[1000001];
    for ( long long i = 0; i <= k; i++ ){
        darab[i] = 0;
    }
    for ( long long j = 1; j <= n; j++ ){
        darab[a[j]]++;
    }
    for ( long long i = 1; i <= k; i++ ){
        darab[i] = darab[i] + darab[i - 1];
    }
    for ( long long j = n; j >= 1; j-- ){
        b[darab[a[j]]] = a[j];
        darab[a[j]] = darab[a[j]] - 1;
    }
    for ( long long i = 1; i <= n; i++ ){
        a[i] = b[i];
    }
}

void be ( long long &n, long long tomb[] ){
    cin >> n;
    for ( long long i = 1; i <= n; i++ ) cin >> tomb[i];
}

int main(){
    long long n = 1, tomb[1000001] = {0}, k = 1000000;
    be(n, tomb);
    StableCountsort(n, tomb, k);
    for ( long long i = 1; i <= n; i++ ) cout << tomb[i] << endl;
    return 0;
}