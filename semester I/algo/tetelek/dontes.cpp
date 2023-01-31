#include<iostream>
using namespace std;

bool T ( int x ){

}

int dontes1 ( int n, int a[], bool talalt ){
    talalt = false;
    for ( int i = 1; i<= n; i++ ){
    talalt = talalt or T(a[i]);
    }
    return talalt;
}

int dontes2 ( int n, int a[], bool talalt ){
    int i = 1;
    talalt = false;
    while ( !talalt && ( i <= n ) ){
        if ( !T( a[i] ) ) i++;
        else talalt = true;
    }
    return talalt;
}

int dontes3 ( int n, int a[], bool talalt ){
    int i = 1;
    talalt = false;
    while ( i <= n && !T(a[i]) ) i++;
    talalt = ( i <= n );
}

int dontes4 ( int n, int a[], bool mind ){
    int i = 1;
    mind = false;
    while ( ( i <= n ) && T(a[i]) ){
        i++;
    }
    mind = i > n;
}
int main(){
    return 0;
}