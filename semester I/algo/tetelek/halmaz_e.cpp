#include<iostream>
using namespace std;

bool halmaz_e ( int n, int a[], int ok ){
int i = 1;
ok = true;
while ( ok and i < n ){
    int j = i + 1;
    while ( j <= n && (a[i] != a[j]) ){
    j++;
    }
    ok = j > n;
    i++;
}
}

int main (){
    return 0;
}