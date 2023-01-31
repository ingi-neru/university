//Laszlo Kazmer
//512
//4
//Szamitsuk ki egy haromszog teruletet, ha ismerjuk oldalainak a hosszat! Az oldalakhosszai 64-bites valos szamok
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main(){
    double a,b,c,s = 0.00;
    cin >> a >> b >> c;
    s=( a + b + c ) / 2;
    cout << fixed << setprecision(2) << sqrt ( s * ( s - a ) * ( s - b ) * ( s - c ));
    return 0;
}