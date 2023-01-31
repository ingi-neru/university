// Bonuszfeladat, Laszlo Kazmer 512
// Adottak n és s természetes számok (1 ≤ n ≤ 1000, 1 ≤ s ≤ 1000000). 
// Elhelyezhetjük-e a + és - műveleti jeleket az 1, 2, . . . , n számok közé (ebben a sorrendben), úgy, hogy az eredmény s legyen? 
// Írjunk ki egy tetszőleges megoldást, vagy -1-et, ha nem létezik ilyen!

#include<iostream>
using namespace std;

// mivel tudjuk hogy a sorrend felteltenul +,-,+,... ezert greedy modszerrel is megoldhato a feladat, nem szukseges backtrackinget hasznalni
// ez implementalva egy minden ciklus lesz ami vegig megy 1tol n-ig es ellenorzi hogy az s felirhato-e a megadott keplettel

bool felirhatoMuveletekkel ( long n, long s ){
    long osszeg = s;
    for ( long i = 1; i <= n; i++ ){// mivel az s ismert, forditott muveletek soran akkor kapunk megoldast, ha az osszeg valtozo 0 lesz
        if ( i % 2 ) osszeg -= i;// ha a szam paratlan, akkor neki megfeleltetjuk a + elojelet keplet szerint
        else osszeg += i;// ellenkezo esetben -at
    }
    return osszeg == 0;
}

void pluszEsMinusz ( long n, long s ){// az alprogram amiben meghivjuk a problemat megoldo alprogramot, s kiiratjuk az eredmenyt
    if ( felirhatoMuveletekkel(n, s) ){
        cout << 1;
        for ( long i = 2; i <= n; i++ ){
            if ( i % 2 ) cout << "+";
            else cout << "-";
            cout << i;
        }
    }
    else cout << -1;// abban az esetben ha nem lehet felirni s-et valtakozva + es - jeleket helyezve a szamok koze, -1et irunk ki
}

int main(){
    long n, s, osszeg = 0;
    cin >> n >> s;
    pluszEsMinusz(n, s);
    return 0;
}