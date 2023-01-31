//Laszlo Kazmer
//512
//Lab2/8
//Vizsgáljuk meg, hogy egy adott, 𝑛×𝑛 méretű négyzetes tömb bűvös négyzet-e vagy sem. 
//Egy természetes számokkal feltöltött négyzetes tömböt akkor nevezünk bűvös négyzetnek, ha páronként különböző számokat tartalmaz, a számok összege soronként és oszloponként, valamint a két átló mentén azonos.
#include<iostream>
using namespace std;

void be ( unsigned long &n, unsigned long a[][11],unsigned long sor_oszlop[], bool &t){
    int sorsz = 1;
    cin >> n;
    for ( unsigned long i = 1; i <= n; i++ ){
        unsigned long sor = 0;
        for ( unsigned long j = 1; j <= n; j++ ){
        cin >> a[i][j];
        sor += a[i][j];
        if ( j > 1 && a[j][i] == a[i][j-1] ) t = false;
        }
        sor_oszlop[sorsz] = sor;
        sorsz++;
    }
}

void hozzaad_oszlop ( unsigned long n, unsigned long a[][11],unsigned long sor_oszlop[], bool &t ){
    int sorsz = n + 1;
    for ( unsigned long i = 1; i <= n && t; i++ ){
        unsigned long oszlop = 0;
        for ( unsigned long j = 1; j <= n && t; j++ ){
        oszlop += a[j][i];
        if ( j < n && a[j][i] == a[j+1][i] ) t = false;
        }
        sor_oszlop[sorsz] = oszlop;
        sorsz++;
    }
}

bool halmaz_e ( unsigned long &n, unsigned long a[], bool ok ){
unsigned long i = 1;
ok = true;
while ( ok and i < n ){
    unsigned long j = i + 1;
    while ( j <= n && (a[i] == a[j]) ){
    j++;
    }
    ok = j > n;
    i++;
}
return ok;
}

int main(){
    unsigned long a[11][11], sor_oszlop[121],n;
    bool ok, t = true;
    be( n, a, sor_oszlop, t );
    hozzaad_oszlop(n, a, sor_oszlop, t);
    if ( halmaz_e( n, sor_oszlop, ok ) && t ) cout << "igen";
    else cout << "nem";
    return 0;
}