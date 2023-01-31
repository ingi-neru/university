//Laszlo Kazmer
//512
//Lab2/3
//Számoljuk meg egy adott szövegben a magánhangzók számát!
#include<iostream>
#include<algorithm>
using namespace std;
int sorozatszamitas ( string szoveg, string maganhangzok, int s ){
s = 0;
for ( int i = 0; i <= maganhangzok.size()-1; i++ ){
s += count( szoveg.begin(), szoveg.end(), maganhangzok[i] );
}
return s;
}
int main(){
    int db = 0;
    string szoveg, maganhangzok="aeiouAEIOU";
    getline( cin, szoveg );
    cout << sorozatszamitas( szoveg, maganhangzok, db );
    return 0;
}