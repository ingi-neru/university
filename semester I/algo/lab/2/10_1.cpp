//Laszlo Kazmer
//512
//Lab2/10
//Adott a következő sorozat, amelynek minden elemét – az elsőt kivéve – az előző elem segítségével generáljuk: 1, 11, 21, 1211, 111221, . . .
//A generálási szabály a következő:
//• megszámoljuk, balról jobbra haladva az előző érték számjegyeit
//• az új értéket úgy kapjuk meg, hogy beírjuk a régi érték összes számjegyeinek előfordulási számát és az illető számjegyet

#include<iostream>
using namespace std;

void masol ( unsigned long seged[], unsigned long elofordulasi[], unsigned long hossz ){
    for ( unsigned long i = 1; i <= hossz; i++ ) seged[i] = elofordulasi[i];
}

void kiiras( unsigned long elofordulasi[] , unsigned long n ){
for ( unsigned long i = 1; i <= n; i++ ) cout << elofordulasi[i];
}

void felepit_kovetkezo ( unsigned long elofordulasi[], unsigned long& hossz ){
unsigned long seged[100001]={0}, seged_hossz = 1, uj_hossz = 1, k = 1;
masol(seged, elofordulasi, hossz);
while ( seged_hossz < hossz ){
k = seged_hossz;
while ( seged[seged_hossz] == seged[seged_hossz + 1] && seged_hossz < hossz ) seged_hossz ++;
if ( seged_hossz > k ) {
    if ( seged_hossz == hossz ) elofordulasi[uj_hossz] = seged_hossz - k + 1, elofordulasi[uj_hossz + 1] = seged[seged_hossz], uj_hossz += 2;
    else elofordulasi[uj_hossz] = seged_hossz - k, elofordulasi[uj_hossz + 1] = seged[seged_hossz], uj_hossz += 2;
}
else elofordulasi[uj_hossz] = 1, elofordulasi[uj_hossz + 1] = seged[seged_hossz], uj_hossz += 2;
}
if ( seged_hossz == hossz && seged[seged_hossz] != seged[seged_hossz - 1] && hossz != 1 ) elofordulasi[uj_hossz] = 1, elofordulasi[uj_hossz + 1] = seged[seged_hossz], uj_hossz += 2;
else if ( hossz == 1 ) elofordulasi[uj_hossz] = 1, elofordulasi[uj_hossz + 1] = seged[seged_hossz], uj_hossz += 2;
hossz = uj_hossz - 1;
}

void fel ( unsigned long n, unsigned long elofordulasi[], unsigned long &hossz ){
unsigned long j = 1;
while ( j != n ){
felepit_kovetkezo( elofordulasi, hossz );
j++;
}
kiiras(elofordulasi, hossz);
}

int main(){
    unsigned long n,elofordulasi[100001] = {0},hossz = 1;
    cin >> n;
    elofordulasi[1] = 1;
    fel( n, elofordulasi, hossz);
    return 0;
}