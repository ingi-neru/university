// Laszlo Kazmer
// 512
// Lab6/8
// Az Encián motelben évekkel előre is fogadnak foglalásokat az odaérkező 𝑛 turistacsoport számára.
// Ismervén a napot, amellyel kezdve foglalni lehet és amelyet 1-el számozunk, a csoportok megjelölik az első és az utolsó napot, amelyet a motelben szeretnének tölteni. 
// Az Encián tulajdonosa mindegyik csoport számára szeretne egy tradicionális előadást szervezni, amire csak a motel dísztermében kerülhet sor, ahova egyszerre csak egy turistacsoport fér be.
// Ezeken az előadásokon fel fog lépni egy előadó, aki megszabja azt az 𝑛 napot, amikor el tud jönni az előadásokra. Segítsetek a tulajdonosnak eldönteni, hogy melyik turistacsoportnak melyik napra szervezze meg az előadást.
#include<iostream>
#include<algorithm>
using namespace std;

void be ( long &n, long eloado[], long kezd[], long veg[]){
    cin >> n;
    for ( long i = 1; i <= n; i++ ){
        cin >> kezd[i] >> veg[i];
    }
        for ( long i = 1; i <= n; i++ ){
        cin >> eloado[i];
    }
}


bool megoldhato( long n, long eloado[], long kezd[], long veg[], long megoldas[][4001] ){
    bool volt[4001] = {false}, volt_eload[4001] = {false};
    for ( long i = 1; i <= n; i++ ){
        long minikezd = 30001, miniveg = 30001, index = 1, minieload = 30001, index_eload = 1;
        for ( long j = 1; j <= n; j++ ){
            if ( kezd[j] < minikezd && !volt[j] ){
            minikezd = kezd[j], miniveg = veg[j], index = j;
            }
            if ( eloado[j] < minieload && !volt_eload[j] ){
            index_eload = j, minieload = eloado[j];
            }
        }
        if ( ( index_eload == 1 && volt_eload[1] ) || !( eloado[index_eload] >= minikezd && eloado[index_eload] <= miniveg ) ) return false;
        else{
            volt[index] = true;
            volt_eload[index_eload] = true;
            megoldas[1][i] = index;
            megoldas[2][i] = index_eload;
        }
    }
    return true;
}

void lefed ( long n,  long eloado[], long kezd[], long veg[] ){
    long megoldas[3][4001] = {0};
    if ( !megoldhato(n, eloado, kezd, veg, megoldas) ) cout << "0 0";
    else{
        for ( long i = 1; i <= n; i++ ){
            cout << megoldas[1][i] << " " << megoldas[2][i] << endl;
        }
    }
}

int main(){
    long n, kezd[4001], veg[4001], eloado[4001];
    be(n, eloado, kezd, veg);
    lefed(n, eloado, kezd, veg);
    return 0;
}