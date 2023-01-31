#include<iostream>
using namespace std;

bool T ( int x ){

}

void keresztmetszet ( int n, int a[], int m, int b[], int db, int c[] ){
    int db = 0;
    for ( int i = 1; i <= n; i++ ){
    int j = 1;
    while ( j <= m and a[i] != b[j] ) j++;
    if ( j <= m ) db++, c[db] = a[i];
    }
}

int main (){
    return 0;
}