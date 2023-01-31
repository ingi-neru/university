#include<iostream>
using namespace std;

int maxkivalaszt1 ( int n, int a[], int maxi ){
    maxi = a[1];
    for ( int i = 2; i <= n ;i++ ){
        if ( maxi < a[i] ) maxi = a[i];
    }
    return maxi;
}
//valtozat 2, maximum helyet teriti vissza
int maxkivalaszt2 ( int n, int a[], int hely ){
    hely = 1;
    for ( int i = 2; i <= n; i++ ){
        if ( a[hely] < a[i] ) hely = i;
    }
    return hely;
}
//valtozat 3, az osszes maximum helyet teriti vissza
void maxkivalaszt3 ( int n, int a[], int db,int indexek[] ){
    int maxi = a[1];
    for ( int i = 2; i <= n ;i++ ){
        if ( maxi < a[i] ) maxi = a[i];
    }
    db = 0;
    for ( int i = 1; i <= n; i++ ){
        if ( a[i] == maxi ) db++, indexek[db] = i;
    }
}
//valtozat 4, az osszes maximum helyet teriti vissza
void maxkivalaszt4 ( int n, int a[], int db, int indexek[] ){
    int maxi = a[1], db = 1;
    indexek[1] = 1;
    for ( int i = 2; i <= n; i++ ){
    if ( maxi < a[i] ) maxi = a[i], indexek[db] = i;
    else if ( maxi == a[i] ) db++,indexek[db] = i;
    }
}

int main(){
    return 0;
}