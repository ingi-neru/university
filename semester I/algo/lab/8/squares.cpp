// Laszlo Kazmer
// 512
// Lab8/5
// Adott egy 𝑛 soros és 𝑚 oszlopos bitmátrix.
// Határozzuk meg a legnagyobb olyan négyzet oldalhosszát, amely a mátrixban található és csak 1-eseket tartal- maz!

#include<iostream>
using namespace std;

void in ( long long &n, long long &m, long long mat[][1001], long long aux[][1001] ){
    cin >> n >> m;
    for ( long long i = 1; i <= n; i++ ){
        for ( long long j = 1; j <= m; j++ ){
            cin >> mat[i][j];
        }
    }
}

long long generateNumOfSquares ( long long n, long long m, long long input[][1001], long long s[][1001] ){
    long long maximum = 0;
    for ( long long i = 1; i <= n; i++ ){
        for ( long long j = 1; j <= m; j++ ){
            if ( input[i][j] != 0 ){
            if ( i > 1 && j > 1 ){
                if ( s[i - 1][j] != 0 && s[i][j - 1] != 0 && s[i - 1][j - 1] ){
                    s[i][j] = min(s[i - 1][j], min( s[i][j - 1], s[i - 1][j - 1])) + 1;
                    if ( maximum < s[i][j] ) maximum = s[i][j];
                }
                else s[i][j] = input[i][j];
            }
            else {
                s[i][j] = input[i][j];
                if ( maximum < s[i][j] ) maximum = s[i][j];
            }
            }
            else {
                s[i][j] = 0;
            }
        }
    }
    return maximum;
}

int main(){
    long long n, m, input[1001][1001], aux[1001][1001];
    in(n, m, input, aux);
    cout << generateNumOfSquares(n, m,input, aux);
    return 0;
}