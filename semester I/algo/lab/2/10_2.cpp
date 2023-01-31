#include<iostream>
using namespace std;

void eloallit_kovetezo ( string &sorozat ){
unsigned long seged_hossz = 0, hossz = sorozat.length() - 1;
string elozo = sorozat, seged = "";
while ( seged_hossz < hossz ){
unsigned long k = seged_hossz;
while ( (elozo[seged_hossz] == elozo[seged_hossz + 1]) && seged_hossz < hossz ) seged_hossz++;
seged = seged + to_string(seged_hossz - k + 1) + elozo[seged_hossz], seged_hossz++;
if ( seged_hossz > hossz ) seged_hossz--;
}
if ( elozo[seged_hossz] != elozo[seged_hossz - 1] && hossz > 0 ) seged = seged + "1" + elozo[seged_hossz];
else if ( hossz == 0 ) seged = seged + "1" + elozo[hossz];
sorozat = seged;
}

void iteral ( int n, string sorozat ){
    for ( int i = 2; i <= n; i++ ){
    eloallit_kovetezo(sorozat);
    }
    cout << sorozat;
}

int main(){
    string sorozat;
    int n;
    sorozat = "1";
    cin >> n;
    iteral(n, sorozat);
    return 0;
}