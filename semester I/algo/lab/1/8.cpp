//Laszlo Kazmer
//512
//8
//Szamıtsuk ki hany szokoev volt/lesz ket kulonbozo evszam kozott!
#include<iostream>
using namespace std;
void osszeadas ( unsigned long long &a, unsigned long long &b ){
    a = a + b;
    b = a - b;
    a = a - b;
}
int main(){
    unsigned long long ev1,ev2,db=0;
    cin>>ev1>>ev2;
   if ( ev1 < ev2 ){
    osszeadas(ev1,ev2);
   }
    if( ev1 != 0 && ev2 != 0 ) db=( ev1 / 4 - ev1 / 100 + ev1 / 400 ) - ( (ev2-1) / 4 - (ev2-1) / 100 + (ev2-1) / 400 );
    else if( ev1 == ev2 && ev1 == 0 ) cout<<1;
    else if ( ev2 == 0 ) {
        db=( ev1 / 4 - ev1 / 100 + ev1 / 400 );
    }
    cout<<db;
    return 0;
}