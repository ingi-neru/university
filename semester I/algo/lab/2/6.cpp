//Laszlo Kazmer
//512
//Lab2/6
//Ismerjük két szám prímszám osztóit, határozzuk meg a két szám legkisebb közös többszörösének prímszám osztóit! 
//(A két számot nem ismerjük, csupán a prim osztóikat).

#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<climits>
using namespace std;

void be ( string &k ){
getline(cin, k);
}

void feldolgoz ( string &a, unsigned long x[], unsigned long &db){
stringstream k;
k << a;
unsigned long tombelem, i = 1;
while ( k >> tombelem ){
x[i] = tombelem, i++;
}
db = i - 1;
}

void egyesites ( unsigned long n, unsigned long a[], unsigned long m, unsigned long b[], unsigned long &db, unsigned long c[] , bool &t ){
db = n;
for ( unsigned long i = 1; i <= n; i++ ) {
    if ( a[i] != 1 ) c[i] = a[i];
    else t = false;
}

for ( unsigned long j = 1; j <= m; j++ ){
unsigned long i = 1;
while ( i <=n && a[i] != b[j] ) i++;
if ( i > n && b[j] != 1 )db++, c[db] = b[j];
else if ( b[j] == 1 ) t = false; 
} 
}

int main (){
    string a, b;
    unsigned long x[10001], y[10001], x_hossz, y_hossz, osszef[100001]={0}, db=1, i;
    bool t = true;
    be(a);
    be(b);
    feldolgoz(a,x,x_hossz);
    feldolgoz(b,y,y_hossz);
    sort(x,x+x_hossz);
    sort(y,y+y_hossz);
    egyesites(x_hossz, x, y_hossz, y, db, osszef,t);
    sort(osszef,osszef+db+1);
    if ( osszef[1] ) cout << osszef[1] << " ";
    i = 2;
    while ( i <= db ){
        cout << osszef[i] <<" ";
        i++;
    }
    
    return 0;
}