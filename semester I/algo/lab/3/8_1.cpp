//Laszlo Kazmer
//512
//Lab3/8
//Bontsunk törzstényezőkre egy adott természetes számot!
#include<iostream>
#include<climits>
#include<cmath>
using namespace std;

void kiir_torzstenyezok ( unsigned long long n ){
unsigned long long db = 0, m = n;
while ( m % 2 == 0 ) m /= 2, db++;
if ( db > 0 ) {
    cout << 2;
if ( db > 1 )  cout << "^" << db;
if ( m > 1 ) cout << "*";
}
for (unsigned long long oszto = 3; oszto <= sqrt(m); oszto += 2) {
    db = 0;
     while (m % oszto == 0) {
        db++;
        m /= oszto;
    }
    if ( db > 0 ) {
    cout << oszto;
    if ( db > 1 )  cout << "^" << db;
    if ( m > 1 ) cout << "*";
    }
    
}
if ( m > 2 ) cout << m;
}

int main(){
    unsigned long long n;
    cin >> n;
    if ( n <= ULLONG_MAX )
    kiir_torzstenyezok(n);
    return 0;
}