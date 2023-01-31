//Laszlo Kazmer
//512
//Lab2/5
//Adott 𝑛 programozó fizetése. 
//Válogassuk szét őket a fizetésük alapján. 
//Az első csoportba azok kerülnek, akiknek a fizetésük nagyobb mint 1000 EUR,
//a másodikba a megmaradtak közül azok, akiknek a fizetése nagyobb mint 700 EUR, 
//a harmadikban maradnak a többiek (a sorrend nem fontos). 
//Törekedjünk egyetlen tömbbel dolgozni és abban elvégezni a szétválogatást, nem elég a kiíratásban csoportokra osztani a számokat.
#include<iostream>
using namespace std;

void be ( unsigned long &n, unsigned long a[] ){
    cin >> n;
    for ( unsigned long i = 1; i <= n; i++ ) cin >> a[i]; 
}

void szetvalogatas1 ( unsigned long n, unsigned long a[], unsigned long &dbb, unsigned long b[], unsigned long &dbc, unsigned long c[] ){
    dbb = 0;
    dbc = 0;
    for ( unsigned long i = 1; i <= n ;i++ ){
        if ( a[i] > 1000 ) dbb++, b[dbb] = a[i];
        else if ( a[i] > 700 ) dbc++, c[dbc] = a[i];
    }
}

void ki ( unsigned long n, unsigned long a[], unsigned long &dbb, unsigned long b[], unsigned long &dbc, unsigned long c[] ){
    for ( unsigned long i = 1; i <= dbb; i++ ) cout << b[i] << " ";
    cout<<endl;
    for ( unsigned long i = 1; i <= dbc; i++ ) cout << c[i] << " ";
    cout<<endl;
    for ( unsigned long i = 1; i <= n; i++ ) if ( a[i] <= 700 ) cout << a[i] << " ";
}
int main(){
    unsigned long n, fizu[500001],fizu700[500001],fizu1000[500001],f1_hossz,f2_hossz;
    be ( n, fizu );
    szetvalogatas1(n, fizu, f1_hossz, fizu700, f2_hossz, fizu1000); 
    ki( n, fizu, f1_hossz, fizu700, f2_hossz, fizu1000 );
    return 0;
}