// Laszlo Kazmer
// 512
// Lab8/4
// Adott egy 𝑛 soros és 𝑚 oszlopos bitmátrix. 
// Határozzuk meg az olyan utak számát, 
//amelyek a mátrix bal felső sarkából indulnak és a jobb alsó sarkába érkeznek, minden lépésben vagy lefelé vagy jobbra haladnak és csak azokra a mezőkre léphetnek, melyek értéke 1. 
// Garantált, hogy a bal felső és jobb alsó sarokban 1-es érték található.

#include<iostream>
using namespace std;

void in ( long &n, long &m, long mat[][31], long aux[][31] ){
    cin >> n >> m;
    for ( long i = 1; i <= n; i++ ){
        for ( long j = 1; j <= m; j++ ){
            cin >> mat[i][j];
            aux[i][j] = mat[i][j];
        }
    }
}

void generateNumOfRoads ( long n, long m, long roads[][31] ){
    for ( long i = 1; i <= n; i++ ){
        for ( long j = 1; j <= m; j++ ){
            if ( roads[i][j] != 0 ){
            if ( i > 1 && j > 1 ){
                roads[i][j] = roads[i - 1][j] + roads[i][j - 1];
            }
            else if ( j > 1 ){
                roads[i][j] = roads[i][j - 1];
            }
            else if ( i > 1 ){
                roads[i][j] = roads[i - 1][j];
            }
            }
        }
    }
}

int main(){
    long n, m, roads[31][31], aux[31][31];
    in(n, m, roads, aux);
    generateNumOfRoads(n, m, aux);
    cout << aux[n][m];
    return 0;
}