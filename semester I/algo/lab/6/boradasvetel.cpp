// Laszlo Kazmer
// 512
// Lab6/3
// Egy falu főútcáján 𝑛 lakos él, minden két egymás melletti ház között ugyanakkora a távolság.
// A falu jó bortermő vidéken található, így a lakók szívesen fogyasztanak, de adnak is el bort.
// Érdekes módon a falun belül a kereslet és a kínálat mindig egyenlő.
// Tudván, hogy két egymás melletti ház között szállítani egy liter bort mindig egy egységnyi munkába kerül és ismervén,
// hogy melyik lakos hány liter bort szeretne eladni vagy vásárolni, határozzuk meg a minimális munkamennyiséget,
// amely szükséges ahhoz, hogy minden lakos igénye ki legyen elégítve.

#include<iostream>
using namespace std;

void be ( long &n, long bor[] ){
    cin >> n;
    for ( long i = 1; i <= n; i++ ) cin >> bor[i];
}

long adasvetel ( long n, long bor[] ){
    long megoldas = 0;
    for ( long i = 1; i < n; i++ ){
    megoldas += abs(bor[i]);
    bor[i + 1] += bor[i];
    }
    return megoldas;
}

int main (){
    long n, bor[100001];
    be(n, bor);
    cout << adasvetel(n, bor);
    return 0;
}