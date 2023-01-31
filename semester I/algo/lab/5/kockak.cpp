// Laszlo Kazmer
// 512
// Lab5/4
// Legyen 𝑛 építőkocka, amelyek 1-től 𝑛-ig vannak címkézve. Beolvassuk az oldalaik hosszát és a színüket.
// Írjunk ki minden 𝑘 kockából álló tornyot, amelyeket úgy építhetünk fel, hogy nem teszünk egymásra azonos színű kockát 
// és oldalaik mérete (lentről felfele) szigorúan csökkenő sorozatot alkotnak.

#include<iostream>
using namespace std;

bool folytat ( unsigned long i[], unsigned long k, unsigned long oldalak[], string szinek[] ){
    unsigned long db = 0;
    if ( k == 1 ) return true;
    else if ( (oldalak[i[k - 1]] <= oldalak[i[k]]) || (szinek[i[k]] == szinek[i[k - 1]]) ) return false ;
    else{
    return true;   
    } 
}

void kocka ( unsigned long n, unsigned long i[], unsigned long k, unsigned long oldalak[], unsigned long magassag, string szinek[], unsigned long &megoldas ){
    if ( k == magassag + 1 ) {
    megoldas++;
        for ( unsigned long j = 1; j <= magassag; j++ ) cout << i[j] << " ";
        cout << endl;
    }
    else{
        for ( unsigned long j = 1; j <= n; j++ ){
            i[k] = j;
            if ( folytat(i, k, oldalak, szinek) ) kocka(n, i, k + 1, oldalak, magassag, szinek, megoldas);
        }
    }
}

int main(){
    unsigned long i[11], k = 1, oldalak[11], ossz = 0, n, magassag, megoldas = 0;
    string szinek[11];
    cin >> n >> magassag;
    for ( unsigned long i = 1; i <= n; i++ ) cin >> szinek[i] >> oldalak[i];
    kocka (n ,i, k, oldalak, magassag, szinek, megoldas);
    if ( megoldas == 0 ) cout << -1;
    return 0;
}