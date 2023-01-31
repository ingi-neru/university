// Laszlo Kazmer
// 512
// Lab8/2
// Számoljátok ki 𝑛 elem 𝑘-ad rendű kombinációinak számát feljegyzéses mód- szerrel
#include<iostream>
using namespace std;

long combOfNandK ( long c[][51], long n, long k ){
    c[1][0] = 1;
    c[0][0] = 1;
    for ( long i = 1; i <= n; i++ ){
        c[i][0] = 1;
        c[i][i] = 1;
        for ( long j = 1; j < i; j++ ){
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    return c[n][k];
}

int main(){
    long combinations[51][51], n, k;
    cin >> n >> k;
    cout << combOfNandK(combinations, n, k) << endl;
    return 0;
}