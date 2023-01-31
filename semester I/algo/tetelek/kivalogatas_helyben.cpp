#include<iostream>
using namespace std;

bool T ( int x ){

}
void kivalogatas_helyben ( int n, int a[] ){
    int i = 1;
    while ( i <= n ){
        if ( !T(a[i]) ) a[i] = a[n], n--;
        else i++;
    }
}

void kivalogatas_helyben2 ( int n, int a[], int db ){
    db = 0;
    for ( int i = 1; i <= n; i++ ){
        if ( T(a[i]) ) db++, a[db] = a[i];
    }
}

int main(){
    return 0;
}