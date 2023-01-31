#include<iostream>
#include<cmath>
using namespace std;
int lnko ( int n, int m ){
if ( n % m == 0 ) return m;
else
{
    for ( int i=m;i>=1;i-- ) {
    if ( m % i == 0 && n % i == 0 ) return i;
    }
}
return 1;
}
int main(){
    int a,b,c,l;
    cin>>a>>b>>c;
    if ( a < b ){
    int aux=a;
    a=b;
    b=aux;
}
l=lnko(a,b);
if ( l < c ){
    int aux=l;
    l=c;
    c=aux;
}
    cout<<lnko(l,c);
    return 0;
}