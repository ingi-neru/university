//Laszlo Kazmer
//512
//Lab4/6
//Írjunk rekurzív algoritmust, amely kiír egy 𝑛 természetes számot törzstényezőkre bontva! 
//Ne használjunk egyáltalán ismétlő struktúrát!
#include<iostream>
#include<cmath>
using namespace std;

void torzstenyezok_rek (unsigned long long eredeti, unsigned long long n , unsigned long long oszto, unsigned long long db ){
    if ( oszto * oszto <= n ){
        if ( n % oszto == 0 && n != 1 ){
            db++;
            torzstenyezok_rek(eredeti, n/oszto, oszto, db);
        }
        else {
            if ( db > 0 ) {
                if ( db > 1 ) cout << oszto << "^" << db << "*";
                else cout << oszto <<"*";
            }
            if ( oszto == 2 ) oszto++;
            else oszto += 2;
            db = 0;
            torzstenyezok_rek(eredeti, n, oszto, db);
        }
    }
    else{
        if ( n == oszto ){
            if ( db > 0 ) cout << oszto << "^" << db+1;
            else cout << oszto;
        }
        else if ( eredeti % oszto == 0 && eredeti >= oszto ) {
            if ( db > 1 ) cout << oszto << "^" << db << "*" << n;
            else cout << oszto << "*" << n;
        }
        else cout << n;
    }
}

int main (){
    unsigned long long n, eredeti;
    cin >> n;
    eredeti = n;
    if ( n > 1 ) torzstenyezok_rek(eredeti, n, 2, 0);
    return 0;
}