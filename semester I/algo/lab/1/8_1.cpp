//U ́tmutat ́as: A sz ̈ok ̋o ́ev oszthat ́o 4-gyel  ́es nem oszthat ́o 100-zal, vagy oszthat ́o 400-zal. P ́eld ́aul 1964 sz ̈ok ̋o ́ev, 1900 nem sz ̈ok ̋o ́ev, 2000 sz ̈ok ̋o ́ev.
#include<iostream>
using namespace std;
bool szokoev ( int n ){
    return( ( n % 4 == 0 && n % 100 != 0 ) || ( n % 400 == 0 ) );
}
void osszeadas ( unsigned long long &a, unsigned long long &b ){
    a = a + b;
    b = a - b;
    a = a - b;
}
int main(){
    unsigned long long ev1,ev2,db=0;
    cin >> ev1 >> ev2;
    if( ev1 < ev2 ) osszeadas( ev1, ev2);
    while( !(szokoev(ev1)) ) ev1--;
    while( !(szokoev(ev2)) ) ev2++;
    for( int i=ev2;i<=ev1;i+=4 ){
        if( szokoev(i) ) {
            if ( i % 400 ){
                while( i + 400 <= ev1 ){
                    db+=97;
                    i+=400;
                }
            }
            else db++;
        }

    }
    cout<<db;
    return 0;
}
