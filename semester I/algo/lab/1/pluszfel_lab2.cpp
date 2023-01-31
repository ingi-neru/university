#include<iostream>
using namespace std;

int main(){
    unsigned long n,db,i=2,a[1001]={0};
    cin>>n;
    db=n;
    a[2]=1;
    unsigned long drb=1;
    while ( db != 1 ){

    
    while ( drb != 2 ){
    if ( a[i] == 0 && db != 1 ) drb++;
    if ( drb == 2 ) db--,a[i] = 1,cout<<i<<endl;
    if ( db == 1 ) drb = 2;
    }
    drb=0;
    if ( i == n ) i = 2;
    else i+=2;
    if( a[i] == 1 ){
    while ( a[i] == 1 ){
    i++;
    }
    }
    
    }
    cout<<i;
    return 0;
}