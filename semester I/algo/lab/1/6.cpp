//Laszlo Kazmer
//512
//6
//Adott három szigorúan pozitív 64-bites valós szám (double): 𝑎, 𝑏, 𝑐. Képezhetik- e ezek a számok egy háromszög oldalait? Ha igen, határozzuk meg és írjuk ki
//a háromszögbe írt, illetve a háromszög köré írt kör sugarát! Ha nem, írjunk ki
//-1-et!
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main(){
    double a , b , c , s;
    cin >> a >> b >> c;
    s = ( a + b + c ) / 2;
    if ( a < b + c && b < a + c && c <  a + b )
    {
    cout << fixed << setprecision(3);
    cout << ( sqrt ( s * ( s - a ) * ( s - b ) * ( s - c ) ) ) / ( ( a + b + c ) / 2 )  << " " << ( a * b * c ) / ( 4 * ( sqrt ( s * ( s - a ) * ( s - b ) * ( s - c ) ) ) );
    }
    else cout<<-1;
    return 0;
}