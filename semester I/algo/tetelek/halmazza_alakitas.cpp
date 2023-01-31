#include<iostream>
using namespace std;

bool T ( int x ){

}

void halmazza ( int n, int a[] ){
    int i = 1, j = i + 1;
    while ( i < n ){
        while ( j <= n and a[i] != a[j] ) j++;
        if ( j <= n ) a[j] = a[n], n--;
        else i++, j = i + 1;
    }
}

int main (){
    return 0;
}