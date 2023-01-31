//Laszlo Kazmer
//512
//3
//Olvassunk be a billentyuzetrol 3 64-bites előjeles egész számot
#include<iostream>
using namespace std;

void sorrend ( int a, int b, int c ){
    if ( a < b ){
        if ( b < c ) cout << a << " " << b << " " << c;
        else if ( a < c ) cout << a << " " << c << " " << b;
        else cout << c << " " << a << " " << b;
    }
    else{
        if ( a < c ) cout << b << " " << a << " " << c;
        else if ( b < c ) cout <<b << " " << c << " " << a;
        else cout << c << " " << b << " " << a;
    }
}

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    sorrend( a, b, c);
    return 0;
}