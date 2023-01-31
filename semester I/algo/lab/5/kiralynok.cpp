// Laszlo Kazmer
// 512
// Lab5/2
// Helyezzünk el 𝑛 darab királynőt egy 𝑛 × 𝑛-es sakktáblán minden lehetséges módon, úgy, hogy ne üssék egymást.
// Számoljuk meg, hogy hányféleképpen lehetséges ez és írassuk ki a megadott sorszámú konfigurációkat a lexikografikus sorrendet tekintve.

#include<iostream>
using namespace std;


bool megvan ( long long q[], long long q_darab, long long szam ){
    for ( long long i = 1; i <= q_darab; i++ ) {
        if ( szam == q[i] ) return true;
    }
    return false;
}

void kiir ( long long aktualis[][15], long long n, long long q_darab, long long q[] ){

for ( long long k = 1; k <= q_darab; k++ ){
for ( long long i = 1; i <= n; i++ ){
    for ( long long j = 1; j <= n; j++ ){
        if ( aktualis[q[k]][i] == j ) cout << "Q";
        else cout << ".";
    }
    cout << endl;
}
cout << endl;
}

}

void kiralyno ( long long v[], long long k, long long n, long long q[], long long q_darab, long long &config, long long &sorsz, bool oszlop[], bool foatlo[], bool mellekatlo[], long long aktualis[][15], long long &db ){
    for ( long long i = 1; i <= n; i++ ){
        v[k] = i;
        if ( !oszlop[i] && !foatlo[i - k + 14] && !mellekatlo[k + i - n - 1 + 14]){
        oszlop[i] = true;
        foatlo[i - k + 14] = true;
        mellekatlo[k + i - n - 1 + 14] = true;
            if ( k < n ) kiralyno(v, k + 1, n, q, q_darab, config, sorsz, oszlop, foatlo, mellekatlo, aktualis, db);
            else {
                if ( megvan(q, q_darab, config)) {
                    db++;
                    for ( long long j = 1; j <= n; j++ ) aktualis[config][j] = v[j];
                }
                config++;
            }
        oszlop[i] = false;
        foatlo[i - k + 14] = false;   
        mellekatlo[k + i - n - 1 + 14] = false;
        }
    }

}

int main(){
    long long n, v[15], q[11], q_darab, k = 1, config = 1, sorsz = 1, aktualis[365][15], db = 0;
    bool oszlop[15] = {0}, foatlo[30] = {0}, mellekatlo[30]= {0};
    cin >> n >> q_darab;
    for ( long long i = 1; i <= q_darab; i++ ) cin >> q[i];
    kiralyno(v, k, n, q, q_darab, config, sorsz, oszlop, foatlo, mellekatlo, aktualis, db);
    if ( db > 0 ){
    kiir(aktualis, n, db, q);
    }
    config--;
    cout << config;
    return 0;
}