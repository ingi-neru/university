//Laszlo Kazmer
//512
//10
//Irjunk ki egy, a 60-as szamrendszerben megadott szamot a 10-es szamrendszerben!
#include<iostream>
#include<string>
#include<cmath>
using namespace std;
unsigned long long tizesszamrendszer ( string be , bool &t ){
unsigned long long n , k = 0  , uj = 0 ;
    for( int i = be.size() - 1 ; i >= 0 ; i-- ){
        if ( be[i] == ')' ){
        n=( ( int )be[i-2] - 48 ) * 10 + ( int )be[i-1] - 48;
        i -= 3;
        }
        else n = ( int )be[i] - 48;
        uj +=pow ( 60 , k ) * n;
        if ( uj >= 4294967295 ) t=true;
        k++;
    } 
    return uj;
}
int main(){
    string be;
    cin>>be;
    unsigned long long uj = 0;
    bool t = false;
    uj = tizesszamrendszer( be , t );
    if ( t ) cout<<-1;
    else cout<<uj;
    return 0;
}