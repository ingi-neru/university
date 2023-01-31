#include<iostream>
using namespace std;
long long b[11], n;

void kiir ( long long darab[], long long n){
for ( long long i = 1; i < n; i++ ){
    if ( darab[i] > 0 ) {
    if ( darab[i] > 1) cout << darab[i] << "*" << b[i] << "+";
    else cout << b[i] << "+";
    }
}
 if ( darab[n] > 0 ) {
    if ( darab[n] > 1) cout << darab[n] << "*" << b[n];
    else cout << b[n];
 }
 cout << endl;
}
void fizet ( long long darab[], long long k, long long sum ){
    if ( k == n ){
        if ( sum % b[n] == 0 ){
            darab[n] = sum / b[n];
            cout << sum << "=", kiir(darab, k);
        }
    }
    else {
        for ( darab[k] = 0; darab[k] <= sum / b[k]; darab[k]++ ){
            long long maradt = sum - (darab[k] * b[k]);
            if ( maradt == 0 ) cout << sum << "=", kiir(darab, k);
            else fizet(darab, k + 1, maradt);
        }
    }
}


int main(){
    long long darab[11] = {0}, k = 1, sum;
    cin >> n;
    for ( long long i = 1; i <= n; i++ ) cin >> b[i];
    cin >> sum;
    fizet(darab, k, sum);
    return 0;
}