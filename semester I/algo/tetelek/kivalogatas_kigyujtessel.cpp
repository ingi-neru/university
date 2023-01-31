#include<iostream>
using namespace std;

bool T ( int x ){}

void kivalogatas_kigyujtessel ( int n, int a[], int db, int poziciok[] ){
db = 0;
for ( int i = 1; i <= n; i++ ) {
    if ( T(a[i]) ) db++, poziciok[db] = i;
}
}

int main(){

    return 0;
}