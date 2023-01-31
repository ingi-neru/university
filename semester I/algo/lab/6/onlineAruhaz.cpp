// Laszlo Kazmer
// 512
// Lab6/9
// Egy online áruház 𝑛 terméket kínál eladásra és mindegyikre ismert a profit mely az eladásából származik és a határidő, ameddig el lehet adni.
// Mivel az áruháznak nagyon kevés alkalmazottja van, egy napon csak egy terméket tud eladni.
// Határozzuk meg a maximális profitot amire az áruház szert tehet!
#include<iostream>
using namespace std;

void be( long profit[], long hatarido[], long &n, long &max_hatarido ){
    cin >> n;
    for ( long i = 1; i <= n; i++ ){
        cin >> profit[i] >> hatarido[i];
        if ( hatarido[i] > max_hatarido ) max_hatarido = hatarido[i];
    }
}

void beszurorendezes ( long n, long profit[], long hatarido[], long max_hatarido){
    for ( long j = 2; j <= n; j++ ){
    long seged1 = hatarido[j], seged2 = profit[j], i = j - 1;
    while ( i > 0 && hatarido[i] > seged1 ){
        hatarido[i + 1] = hatarido[i];
        profit[i + 1] = profit[i];
        i--;
    }
    hatarido[i + 1] = seged1;
    profit[i + 1] = seged2;
    }
    for ( long j = 2; j <= min(max_hatarido, n); j++ ){
    long seged1 = hatarido[j], seged2 = profit[j], i = j - 1;
    while ( i > 0 && hatarido[i] > seged1 ){
        hatarido[i + 1] = hatarido[i];
        profit[i + 1] = profit[i];
        i--;
    }
    hatarido[i + 1] = seged1;
    profit[i + 1] = seged2;
    }
}

long maximalisProfit ( long n, long profit[], long hatarido[], long max_hatarido ){
    long jelenlegi_hatarido = 1, megoldas = 0, j = 1, index, maxi;
    bool volt[10001] = {false};
    while ( jelenlegi_hatarido <= min(n, max_hatarido) ){
    j = max(n, max_hatarido);
    index = 1;
    maxi = 0;  
    while ( j >= 1 ){
        if ( !volt[j] && maxi < profit[j] && hatarido[j] <= jelenlegi_hatarido + 1 ){

            index = j;
            maxi = profit[j];
        }
        j--;
    }
    megoldas += maxi;
    volt[index] = true;
    jelenlegi_hatarido++;
    }
    return megoldas;
}

int main(){
    long profit[10001], hatarido[10001], n, max_hatarido;
    be(profit, hatarido, n, max_hatarido);
    beszurorendezes(n, profit, hatarido, max_hatarido);
    /**cout << endl;
    for ( long i = 1; i <= n; i++ ){
        cout << profit[i] << " " << hatarido[i] << endl;
    }**/
    cout << maximalisProfit(n, profit, hatarido, max_hatarido);
    return 0;
}