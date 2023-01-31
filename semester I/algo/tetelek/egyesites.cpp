#include<iostream>
using namespace std;

bool T ( int x ){

}

void masol ( int n, int a[], int m, int b[] ){
    for ( int i = 1; i <= n; i++ ) b[i] == a[i];
    m = n;
}

void egyesites ( int n, int a[], int m, int b[], int db, int c[] ){
masol( n, a, db, c );
for ( int j = 1; j <= m; j++ ){
    int i = 1;
    while ( i <= n and a[i] != b[j] ) i++;
    if ( i > n ) db++, c[db] = b[j];
}
}

int main (){
    return 0;
}