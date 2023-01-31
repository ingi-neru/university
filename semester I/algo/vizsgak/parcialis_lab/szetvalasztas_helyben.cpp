#include<iostream>
using namespace std;

void szetvalogatas_helyben ( long long n, long long tomb[], long long &db ){
long long e = 1, v = n;
while ( e < v ){
    while ( tomb[e] < 0 || tomb[v] > 0 ){
    e++;
    v--;
    }
    swap(tomb[e], tomb[v]);
    if ( e < n && tomb[e] < 0) e++;
    if ( v > 1 && tomb[v] > 0 ) v--;
}
if ( e < 0 ) db = e;
else db = e - 1;
}

void be ( long long &n, long long tomb[] ){
cin >> n;
for ( long long i = 1; i <= n; i++ ){
cin >> tomb[i];
} 
}

int main(){
    long long n, tomb[1001], db;
    be(n, tomb);
    szetvalogatas_helyben(n, tomb, db);
    for ( long long i = 1; i <= n; i++ ) cout << tomb[i] << " ";
    return 0;
}