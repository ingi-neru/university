//Laszlo Kazmer
//512
//Lab4/9
//Implementáljuk rekurzívan az orosz szorzás algoritmusát!
#include<iostream>
#include<climits>
using namespace std;

unsigned long long orosz_szorzas_rek( unsigned long long x, unsigned long long y, unsigned long long &eredmeny ){
if ( eredmeny <= ULLONG_MAX - 15 && y != 0 ){
if ( x == 1 ) {
 eredmeny += y;
 return 0;
}
else if ( x % 2 == 0 ) return orosz_szorzas_rek(x/2, y*2, eredmeny);
else {
    eredmeny += y;
    return orosz_szorzas_rek(x/2, y*2, eredmeny);
}
}
else return 0;
}
int main (){
    unsigned long long x, y, eredmeny = 0;
    cin >> x >> y;
    orosz_szorzas_rek(x, y, eredmeny);
    cout << eredmeny;
    return 0;
}