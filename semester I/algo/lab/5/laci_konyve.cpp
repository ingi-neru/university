// Laszlo Kazmer
// 512
// Lab5/7
// Adva van egy 𝑛 személyből álló csoport. 
// Minden személynek van legalább 𝑛/2 barátja a csoporton belül. 
// Lacinak van egy könyve, amelyet a csoport minden tagja el szeretne olvasni.
// Írjátok ki, hogyan vándorol a könyv egyik személytől a másikig úgy, hogy mindenkihez csak egyszer kerül, és egy személy csak egy barátjának kölcsönzi a könyvet, amíg az visszatér Lacihoz. 
// Az összes lehetséges megoldást keressük, a megoldásokat tetszőleges sorrendben ki lehet íratni.

#include<iostream>
using namespace std;

bool nincsMeg ( int k, string meg[], string nev ){
for ( int i = 1; i < k; i++ ) if ( meg[i] == nev ) return false;
return true;
}

bool visszaAd ( int m, string nev, string barat[][31] ){
    for ( int i = 1; i <= m; i++ ){
        if ( (barat[2][i] == "Laci" && barat[1][i] == nev)  || (barat[2][i] == nev && barat[1][i] == "Laci") ) return true;
    }
    return false;
}
void konyv_utja ( int n, int m, int k, string baratok[][31], string meg[] ){
    if ( k == n + 1){
        for ( int i = 1; i <= n; i++ ) cout << meg[i] << " ";
        cout << "Laci" << endl;
    }
    else{
        for ( int i = 1; i <= m; i++ ){
        bool t;
        t = true;
        if ( k == n ) {
        if ( meg[k - 1] == baratok[1][i] ) t = visszaAd(m, baratok[2][i], baratok);
        else if ( meg[k - 1] == baratok[2][i] ) t = visszaAd(m, baratok[1][i], baratok);
        else t = false;
        }
        if ( meg[k - 1] == baratok[1][i] && t && nincsMeg(k, meg, baratok[2][i])) {
            meg[k] = baratok[2][i];
            konyv_utja (n, m, k + 1, baratok, meg);
        }
        else if ( meg[k - 1] == baratok[2][i] && t && nincsMeg(k, meg, baratok[1][i]) ){
            meg[k] = baratok[1][i];
            konyv_utja (n, m, k + 1, baratok, meg);
        }
        }
    }
}

int main(){
    int n, m, k = 2;
    string baratok[3][31], meg[9];
    cin >> n >> m;
    meg[1] = "Laci";
    for ( int i = 1; i <= m; i++ ){
    cin >> baratok[1][i] >> baratok[2][i];
    }
    konyv_utja(n, m, k, baratok, meg);
    return 0;
}