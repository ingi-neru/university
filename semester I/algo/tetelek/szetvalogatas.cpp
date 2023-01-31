#include<iostream>
using namespace std;

bool T( int x ){

}

void szetvalogatas( int n, int a[], int db ){
    int e = 1, u = n, seged = a[e];
    while ( e < u ){
        while ( e < u and !T(a[u]) ) u--;
    }
    if ( e < u ) a[e] = a[u], e++;
    while ( e < u and !T(a[e]) ) e++;
    if ( e < u ) a[u] = a[e], u--; 
}

int main(){


    return 0;
}