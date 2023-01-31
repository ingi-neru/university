#include<iostream>
using namespace std;

void zarojelek ( int meg[], int ny, int n, int k ){
    if ( k == n + 1 ){
        for ( int i = 1; i <= n; i++ ) {
            if ( meg[i] == 1 ) cout << "(";
            else cout << ")";
        }
        cout << endl;
    }
    else{
            if ( ny < n / 2 ) {
                meg[k] = 1;
                zarojelek(meg, ny + 1, n, k + 1);
            }
            if ( 2 * ny - k + 1 > 0 ){
            meg[k] = 2;
            zarojelek(meg, ny, n, k + 1);
            }
    }
}

int main(){
    int meg[11], ny = 0;
    zarojelek(meg, ny, 6, 1);
    return 0;
}