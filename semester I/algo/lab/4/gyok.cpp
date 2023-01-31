//Laszlo Kazmer
//512
//Lab4/10
//Írjunk rekurzív algoritmust, amely meghatározza egy adott 𝑎 szám né-
//gyzetgyökét, felhasználva a következő sorozatot, melyről tudjuk, hogy √𝑎-hoz
//konvergál.
#include<iostream>
#include<climits>
#include<string>
#include<iomanip>
using namespace std;

double gyok_rekurziv ( double a, double ismetel){
if ( a == 0 ) return a;
else if ( ismetel > 0 ){
    double elozo = gyok_rekurziv(a, --ismetel);
    return ( (a / elozo) + elozo ) / 2 ; 
}
else return a;
}


int main(){
    double a, ismetel = 100, gyok = 0;
    cin >> a;
    gyok = gyok_rekurziv(a, ismetel);
    cout << fixed << setprecision(6) << gyok;
    return 0;
}