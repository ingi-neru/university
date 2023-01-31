//Laszlo Kazmer
//512
//Lab2/9
//Ismert sejtés, miszerint ha egy adott 𝑛 természetes számot ismételten alávetünk a következő feldolgozásnak, 
//eljutunk az 1-es számhoz: ha 𝑛 páros, akkor elosztjuk 2-vel, ha 𝑛 páratlan, megszorozzuk 3-mal és az eredményhez hozzáadunk 1-et. 
//Azoknak a lépéseknek a számát, amelyek egy adott 𝑛-ből az 1-hez vezetnek, karakterisztikának nevezzük. 
//Írjunk programot, amely meghatározza azt az 𝑛 számot, amely az [𝑥, 𝑦] intervallumhoz tartozik és amelynek a karakterisztikája a legnagyobb!
#include<iostream>
using namespace std;
int maxkivalaszt2 ( int x, int y, int a[], int hely ){
    hely = y;
    for ( int i = y; i >= x; i-- ){
        if ( a[hely] < a[i] ) hely = i;
    }
    return hely;
}
int collatz ( int x ){
if ( x == 1 ) return 0;
else if ( x % 2 ) return collatz( 3 * x + 1 ) + 1;
else return collatz( x / 2 ) + 1;
}
int main(){
    int x, y, a[1001],hely = 0;
    cin >> x >> y;
    for ( int i = x; i <= y; i++  ){
    a[i] = collatz(i);
    }
    hely = maxkivalaszt2( x, y, a, hely );
    cout << hely << " " << a[hely];
    return 0;
}