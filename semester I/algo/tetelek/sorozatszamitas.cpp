#include<iostream>
using namespace std;

int sorozatszamitas ( int n, int a[], int s ){
s = 0;
for ( int i = 1; i <= n; i++ ){
s += a[i];
}
return s;
}

int main(){
    return 0;
}