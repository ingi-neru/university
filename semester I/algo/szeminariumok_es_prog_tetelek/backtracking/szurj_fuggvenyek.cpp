#include<iostream>
using namespace std;

void szurj_fgv ( long k, long n, long m, long elofordulasi[], long megoldas[], long mj ){
if ( n - k + 1 >= m - mj ){
if ( k == n + 1 ){
    for ( long i = 1; i <= n; i++ ){
        cout << megoldas[i] << " ";
    }
    cout << endl;
    return;
}
else{
    
        
    for ( long i = 1; i <= m; i++ ){
        elofordulasi[i]++;
        megoldas[k] = i;
        if ( elofordulasi[i] == 1 ){
        szurj_fgv(k + 1, n, m, elofordulasi, megoldas, mj + 1);
        elofordulasi[i]--;
        }
        else{
        szurj_fgv(k + 1, n, m, elofordulasi, megoldas, mj);
        elofordulasi[i]--;
        }
    }
    }
}
}

int main (){
    long n, m, megoldas[101], elofordulasi[101] = {0}, mj = 0, k = 1;
    cin >> n >> m;
    szurj_fgv(k, n, m, elofordulasi, megoldas, mj);
    return 0;
}