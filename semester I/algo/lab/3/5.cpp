//Laszlo Kazmer
//512
//Lab3/5
//Adott egy római szám, írjuk ki arab számjegyekkel!
#include<iostream>
#include<string>
using namespace std;

int visszateritArab ( int szamjegyek[], string romai_szamok, unsigned long &arab, string szam ){
arab = 0;
unsigned long hossz = szam.length(), elojel = 1;
arab += szamjegyek[romai_szamok.find(szam[hossz])];
hossz--;
while ( hossz > 0 ){
unsigned long index = romai_szamok.find(szam[hossz]);
if( romai_szamok.find(szam[hossz]) > romai_szamok.find(szam[hossz + 1]) ) elojel = -1;
else elojel = 1;
arab += elojel * szamjegyek[index];
hossz--;
}
if ( hossz >= 0 ) {
if ( romai_szamok.find(szam[hossz]) > romai_szamok.find(szam[hossz + 1]) ) arab -= szamjegyek[romai_szamok.find(szam[hossz])];
else arab += szamjegyek[romai_szamok.find(szam[hossz])];
}
return arab;
}

int main (){
    string romai_szamok = "0MDCLXVI", szam;
    int szamjegyek[1001] = { -1, 1000, 500, 100, 50, 10, 5, 1};
    unsigned long arab;
    getline(cin, szam);
    arab = visszateritArab(szamjegyek, romai_szamok, arab, szam);
    cout << "A megadott szam arab szamjegyekkel: " << arab;
    return 0;
}
