#include<iostream>
using namespace std;

void be ( long k, long t, long a[][1001] ){
    for ( long i = 1; i <= k; i++ ){
        for ( long j = 1; j <= t; j++ ){
            cin >> a[i][j];
        }
    }   
}

void felepit_mini ( long minik[], long repulo[][1001], long mini, long t, long n ){
    for ( long i = 1; i <= t; i++ ){
        mini = repulo[1][i];
        for ( long j = 2; j <= n; j++ ){
        if ( repulo[j][i] < mini ) mini = repulo[j][i];
        }
        minik[i] = mini;
    }
}
void kiszamol_darab ( long minik[], long epulet[][1001], long t, long m, long &db ){
        for ( long i = 1; i <= t; i++ ){
        for ( long j = 1; j <= m; j++ ){
    if ( epulet[j][i] > minik[i] ) db -= epulet[j][i] - minik[i];
    else db += minik[i] - epulet[j][i];
        }
    }
}
int main(){
    long repulo[101][1001], epulet[10][1001], t, n ,m , minik[1001], mini, db = 0;
    cin >> n  >> m >> t;
    be(n, t, repulo);
    be(m, t, epulet);
    felepit_mini( minik, repulo, mini, t, n);
    kiszamol_darab(minik, epulet, t, m, db);
    cout << db;
    return 0;
}