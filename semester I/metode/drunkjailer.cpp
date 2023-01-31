#include<iostream>
using namespace std;

int main(){
    int m,n,j=2,db;
    int a[101]={0};
    cin >> n;
    for ( int ii=1;ii<=n;ii++ ){
    cin>>m;
    db=0;
    for ( int i=1;i<=m;i++ ) a[i]=0;
    for ( int i=2;i<=m;i++ ){
        for( int j=i;j<=m;j+=i){
        if ( a[j] == 0 ) a[j]=1;
        else a[j]=0;
        }
    }
    for ( int i=2;i<=m;i++ ) if( a[i] == 0 ) db++;
    cout<<db+1<<endl;
    }
    return 0;
}