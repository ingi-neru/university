//Laszlo Kazmer
//512
//Lab3/1
//Döntsük el egy adott számról, hogy völgyszám-e vagy hegyszám. 
//Egy völgy- szám számjegyei szigorúan csökkenő sorrendben követik egymást egy bizonyos elemmel bezárólag, majd azzal kezdődően szigorúan növekvő sorozatot alkotnak. 
//A hegyszám számjegyei szigorúan növekvő sorrendben követik egymást egy bizonyos elemmel bezárólag, majd azzal kezdődően szigorúan csökkenő sorozatot alkotnak.
//Írjunk ki egy megfelelő üzenetet, aszerint hogy az adott szám völgyszám-e vagy hegyszám. 
//Ha a szám nem völgyszám és nem hegyszám, vágjuk le a szám első néhány számjegyét amíg az így kapott szám völgyszámmá vagy hegyszámmá válik. 
//Ebben az esetben írjuk ki az adott szám azon részét, amely völgyszám vagy hegyszám, ha létezik ilyen, vagy megfelelő üzenetet, ha nem.
#include<iostream>
#include<ctime>
using namespace std;

void beolvas_es_feldolgoz ( unsigned long long &n, unsigned long long szamj[], unsigned long long &hossz ){
    hossz = 0;
    cin >> n;
    unsigned long long m = n;
    while ( m > 0 ){
    szamj[++hossz] = m % 10;
    m /= 10;
    }
}

void megszamol_valt ( unsigned long long hossz, unsigned long long szamj[], unsigned long long &db, bool &nagyobb, bool &kisebb, unsigned long long &ugyanolyan ){
unsigned long long i = 1;
ugyanolyan = 0;
while ( szamj[i] == szamj[i + 1] && i < hossz ) i++;
if ( i != 1 ) ugyanolyan++;
if ( i != hossz ){
if ( szamj[i] > szamj[i + 1] ) kisebb = true, nagyobb = false;
else kisebb = false, nagyobb = true;
while ( i < hossz ){
    if ( kisebb && szamj[i] < szamj[i + 1] ) db++, kisebb = false, nagyobb = true;
    if ( nagyobb && szamj[i] > szamj[i + 1] ) db++, kisebb = true, nagyobb = false;
    if ( szamj[i] == szamj[i+1] ) ugyanolyan++;
    i++;
}
}
}


void kiir ( unsigned long long hossz, unsigned long long szamj[] ){
for ( int i = hossz; i >= 1; i-- ) cout << szamj[i];
}

void kiir_benne_hegy_volgy ( unsigned long long szamj[], unsigned long long hossz, bool kisebb, bool nagyobb ){
unsigned long long i = 1, db = 0, ugyanolyan = 0;
bool ok = true;
do{
db = 0;
hossz--;
megszamol_valt(hossz, szamj, db, nagyobb, kisebb, ugyanolyan);
if ( db == 1 && nagyobb && !ugyanolyan ) kiir(hossz, szamj), ok = false;
if ( db == 1 && kisebb && !ugyanolyan ) kiir(hossz, szamj), ok = false;
} while ( hossz > 2 && ok );
if ( hossz < 3 ) cout << "nincs benne hegyszam vagy volgyszam";

}
int main(){
    unsigned long long n, szamjegyek[10001], hossz, db = 0, ugyanolyan = 0 ;
    bool nagyobb, kisebb;
    beolvas_es_feldolgoz(n, szamjegyek, hossz);
    megszamol_valt(hossz, szamjegyek, db, nagyobb, kisebb, ugyanolyan);
    if ( db == 0 ) cout << "nincs benne hegyszam vagy volgyszam";
    else if ( db == 1 && nagyobb && !ugyanolyan ) cout << "volgyszam";
    else if ( db == 1 && kisebb && !ugyanolyan ) cout << "hegyszam";
    else if ( db > 1 || ugyanolyan || szamjegyek[hossz] == 0 ) kiir_benne_hegy_volgy(szamjegyek, hossz, kisebb, nagyobb);
    return 0;
}