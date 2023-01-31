#include<iostream>
using namespace std;

int main(){
    unsigned long e, v, elofordulasi[10] = {0};
    cin >> e >> v;
    for ( unsigned long i = e; i <= v; i++ ){
        unsigned long seged = i;
        while ( seged > 0 ){
            elofordulasi[seged % 10]++;
            seged /= 10;
        }
    }
    for ( int i = 0; i <= 9; i++ ) cout << elofordulasi[i] << " ";
    return 0;
}