//Laszlo Kazmer
//512
//Lab3/6
//Adott egy arab szám, írjuk ki római számjegyekkel!
#include<iostream>
using namespace std;

void feldolgoz ( int &arab, int szamjegyek[], int &hossz ){
hossz = 0;
cin >> arab;
int m = arab;
while ( m > 0 ){
szamjegyek[++hossz] = m % 10;
m /= 10;
}
}

void felepit_ezresek ( int x, string &romai ){
for ( int i = 1; i <= x; i++ ) romai += "M";
}

void felepit_szazasok ( int x, string &romai ){
    if ( x == 9 ) romai += "CM";
    else if ( x >= 5 && x != 9 ){
    romai += "D";
    for ( int i = 6; i <= x; i++ ){
    romai += "C";
    }
    }
    else if ( x == 4 ){
    romai += "CD";
    }
    else{
    for ( int i = 1; i <= x; i++ ) romai += "C";
    }
}

void felepit_tizesek ( int x, string &romai ){
    if ( x == 9 ) romai += "XC";
    else if ( x >= 5 && x != 9 ){
    romai += "L";
    for ( int i = 6; i <= x; i++ ){
    romai += "X";
    }
    }
    else if ( x == 4 ){
    romai += "XL";
    }
    else{
    for ( int i = 1; i <= x; i++ ) romai += "X";
    }
}

void felepit_egyesek ( int x, string &romai ){
    if ( x == 9 ) romai += "IX";
    else if ( x >= 5 && x != 9 ){
    romai += "V";
    for ( int i = 6; i <= x; i++ ){
    romai += "I";
    }
    }
    else if ( x == 4 ){
    romai += "IV";
    }
    else{
    for ( int i = 1; i <= x; i++ ) romai += "I";
    }
}

void atalakit_romaiba ( int szamjegyek[], int hossz, string &romai ){
while ( hossz > 0 ){
    if ( hossz == 4 ) felepit_ezresek(szamjegyek[hossz], romai);
    if ( hossz == 3 ) felepit_szazasok(szamjegyek[hossz], romai);
    if ( hossz == 2 ) felepit_tizesek(szamjegyek[hossz], romai);
    if ( hossz == 1 ) felepit_egyesek(szamjegyek[hossz], romai);
    hossz--;
}
}

int main(){
    int arab, szamjegyek[5] = {0}, hossz = 0;
    string romai = "";
    feldolgoz(arab, szamjegyek, hossz);
    atalakit_romaiba(szamjegyek, hossz, romai);
    cout << romai;
    return 0;
}