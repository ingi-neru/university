#include<iostream>
using namespace std;

bool T ( int x ){

}

void kivalogatas_specialis_ertekekkel ( int n, int a[] ){
    for ( int i = 1; i <= n; i++ ){
        if ( !T(a[i]) ) a[i] = -1; //akarmilyen specialis ertek megfelel, feladatfuggo
    }
}

int main (){
    return 0;
}