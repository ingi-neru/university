//Laszlo Kazmer
//512
//9
//Szamitsuk ki hany napot eltunk a mai nappal bezarolag
#include<iostream>
#include<string>
using namespace std;
void osszeadas ( unsigned long &a, unsigned long &b ){
    a = a + b;
    b = a - b;
    a = a - b;
}
int szokoevek(unsigned long ev1, unsigned long ev2){
    unsigned long db=0;
   if ( ev1 < ev2 ){
    osszeadas(ev1,ev2);
   }
    if( ev1 != 0 && ev2 != 0 ) db=( ev1 / 4 - ev1 / 100 + ev1 / 400 ) - ( (ev2-1) / 4 - (ev2-1) / 100 + (ev2-1) / 400 );
    else if( ev1 == ev2 && ev1 == 0 ) cout<<1;
    else if ( ev2 == 0 ) {
        db=( ev1 / 4 - ev1 / 100 + ev1 / 400 );
    }
    return db;
}
bool szokoev ( int n ){
    return( ( n % 4 == 0 && n % 100 != 0 ) || ( n % 400 == 0 ) );
}
int honapok ( unsigned long h ){
    unsigned long t=0;
    if ( h > 1 ){
    if( h == 2 ) t=31;
    else if ( h == 3 ) t=59;
    else if ( h == 4 ) t=90;
    else if ( h == 5 ) t=120;
    else if ( h == 6 ) t=151;
    else if ( h == 7 ) t=181;
    else if ( h == 8 ) t=212;
    else if ( h == 9 ) t=242;
    else if ( h == 10 ) t=273;
    else if ( h == 11 ) t=303;
    else t=334;
    }
    return t;
}
int main(){
    string ev1,ev2;
    cin>>ev1>>ev2;
    unsigned long e1=1000*((int)ev1[0]-48)+100*((int)ev1[1]-48)+10*((int)ev1[2]-48)+(int)ev1[3]-48,h1=10*((int)ev1[5]-48)+(int)ev1[6]-48,n1=10*((int)ev1[8]-48)+(int)ev1[9]-48,
    e2=1000*((int)ev2[0]-48)+100*((int)ev2[1]-48)+10*((int)ev2[2]-48)+(int)ev2[3]-48,h2=10*((int)ev2[5]-48)+(int)ev2[6]-48,n2=10*((int)ev2[8]-48)+(int)ev2[9]-48;
    long long tav1 = 365 * e1 + n1 , tav2 = 365 * e2 + n2;
    tav1 += honapok(h1);
    tav2+=honapok(h2);
    unsigned long tav = tav2-tav1;
    if( szokoev(e1) && h1 > 2 ) tav--;
    else if ( szokoev(e1) && h1 == 2 && n1 == 28 ) tav--;
    if ( szokoev(e2) && h2 < 2 ) tav--;
    else if ( szokoev(e2) && h2 == 2 && n2 < 29 ) tav--;
    cout<<tav+szokoevek(e1 , e2);
    return 0;
}