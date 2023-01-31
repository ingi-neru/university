//Laszlo Kazmer
//512
//Lab2/10
//Adott a következő sorozat, amelynek minden elemét – az elsőt kivéve – az előző elem segítségével generáljuk: 1, 11, 21, 1211, 111221, . . .
//A generálási szabály a következő:
//• megszámoljuk, balról jobbra haladva az előző érték számjegyeit
//• az új értéket úgy kapjuk meg, hogy beírjuk a régi érték összes számjegyeinek előfordulási számát és az illető számjegyet
#include<iostream>
#include<string>
using namespace std;

void eloallit_kovetkezo ( int n, string sorozat ){
string seged = sorozat, eloallit = "";
for ( int i = 0; i < seged.length() - 1; i++ ){
int j = i;
while ( seged[i] == seged[i+1] && i < seged.length() - 1 ){
i++;
}
if ( j != i ) eloallit = eloallit + to_string(i - j) + seged[i];
else eloallit = eloallit + "1" + seged[i];
}
sorozat = eloallit;sorozat = sorozat + "1" + seged[seged.length() - 1];
}


void iteral ( int n, string sorozat ){
    for ( int i = 2; i <= n; i++ ){
    eloallit_kovetkezo(n, sorozat);
    }
    cout << sorozat;
}

int main (){
    string sorozat = "1";
    int n;
    cin >> n;
    iteral(n, sorozat);
    return 0;
}