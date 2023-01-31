#include<iostream>
using namespace std;

bool T ( int x ){

}

int megszamlalas ( int n, int a[], int db ){
    int db = 0;
    for ( int i = 1; i <= n; i++ ){
    if ( T( a[i] ) ) db++;
    }
    return db;
}

int main(){

    return 0;
}