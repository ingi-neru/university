//Laszlo Kazmer
//512
//Lab2/4
//Adott egy csoport év végi vizsgajegyeinek listája. 
//Töröljük ki az 5-ösnél kisebb jegyeket a listából.
//A módósítást a beolvasott tömbben kell elvégezni, nem elég csak kiíratni az eredményt.
#include<iostream>
using namespace std;

void kivalogatas ( double n, double a[], double b[], int& hely, int& m ){
    hely = 1;
    m = 0;
    while ( hely <= n ){
    if( a[hely] >= 5 ) m++, b[m] = a[hely];
    hely++;
    }
}

void be ( double &n, double a[] ){
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i]; 
}

void ki ( double n, double a[] ){
    for ( int i = 1; i <= n; i++ ) cout << a[i] << " ";
}
int main(){
    double n, jegyek[1000001];
    static double masol[1000001];
    int hely = 1 , m = 1;
    be ( n, jegyek );
    kivalogatas( n, jegyek, masol, hely, m );
    ki( m, masol );
    return 0;
}