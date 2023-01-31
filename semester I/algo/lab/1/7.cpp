//Laszlo Kazmer
//512
//7
//
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    long double a , b , c ;
    cin >> a >> b >> c ;
    long double delta = pow ( b , 2 ) - 4 * ( a * c );
    if ( delta > 0 && a != 0 ){
        long double meg1 = ( - b - sqrt( delta ) ) / ( 2 * a ) ,meg2 = ( - b + sqrt( delta ) ) / ( 2 * a );
        if ( ceil( meg1 ) == floor( meg1 ) ){
            cout << fixed << setprecision(0) << meg1 << " ";
            }
        else cout << fixed << setprecision(1) <<round( meg1 * 10.0 ) / 10.0 << " ";
        if ( ceil( meg2 ) == floor( meg2 ) ) {
            cout << fixed << setprecision(0) << meg2;
            }
        else cout << fixed << setprecision(1) <<round( meg2 * 10.0 ) / 10.0;
    }
    else cerr << "Hiba!";
    return 0;
}