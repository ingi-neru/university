#include<iostream>
using namespace std;

bool T ( int x ){

}

void osszefesules4 ( int n, int a[], int m, int b[], int db, int c[] ){
    db = 0;
    int i = 1, j = 1;
    a[ n + 1 ] = INT_MAX;
    a[ m + 1 ] = INT_MAX;
    while ( i <= n || j <= m ) {
        db++;
        if ( a[i] < b[j] ) c[db] = a[i], i++;
        else if ( a[i] == b[j] ) c[db] = a[i], i++, j++;
        else c[db] = b[j], j++;
    }
}
int main (){
    return 0;
}