#include<iostream>
using namespace std;

int main(){
    long n,c[101][101]={0},maxi=-1;
    cin >> n;
    cin >> c[1][1];
    for ( long i=2;i<=n;i++ ){
        for ( long j=1;j<=i;j++ ){
        cin >> c[i][j];
        if ( j == 1 ) c[i][j] += c[i-1][j];
        else if ( j == i ) c[i][j] += c[i-1][j-1];
        else if ( j > 1 && j < i ) c[i][j] += max( c[i-1][j], c[i-1][j-1] );
                                }
                            }
    for ( long i = 1; i <= n; i++ ){
        if ( c[n][i] > maxi ) maxi = c[n][i];
    }
    cout << maxi;
return 0;
}