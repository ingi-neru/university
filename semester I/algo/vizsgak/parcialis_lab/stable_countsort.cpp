//Laszlo Kazmer
//512
//Lab4/4
//Rendezzünk egy 𝑛 elemű tömböt leszámláló rendezéssel!
#include<iostream>
using namespace std;
void CountSort ( long n, long a[], long k, long darab[], long b[] ){
for ( long i = 1; i <= k; i++ ) darab[i] = 0;
for ( long j = 1; j <= n; j++ ) darab[a[j]]++;
for ( long i = 2; i <= k; i++ ) darab[i] = darab[i] + darab[i - 1];
for ( long j = n; j >= 1; j-- ){
    b[darab[a[j]]] = a[j];
    darab[a[j]]--;
}

}
void be ( long &n, long a[] ){
    cin >> n;
    for ( long i = 1; i <= n; i++ ) cin >> a[i];
}
int main(){
    long n , tomb[1000001], k = 1000000, darab[1000001], b[10000001];
    be(n, tomb);
    CountSort(n, tomb, k, darab, b);
    for ( long i = 1; i <= n; i++ ){
        cout << b[i] << endl;
    }
    return 0;
}