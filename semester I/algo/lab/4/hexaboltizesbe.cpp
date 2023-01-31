//Laszlo Kazmer
//512
//Lab4/8
//Írjunk rekurzív algoritmust, amely átalakít egy, a 16-os számrendszerben megadott egész számot a 10-es számrendszerbe!
//Ne használjunk ismétlő struktúrát a beolvasáson kívül!
#include<iostream>
#include<climits>
#include<string>
using namespace std;

unsigned long atalakit ( string szam, long index, unsigned long hatv, unsigned long felepit_szam ){
index--;
if ( hatv == 0 && index > 0 ) {felepit_szam = 0; return 0;}
if ( szam[index] == '-' && index == 0 ) {felepit_szam = 0; return 0;}
if ( index >= 0 ){

if ( szam[index] >= '0' && szam[index] <= '9' ) 
{
 int szamj = (int)szam[index] - 48;
 return atalakit(szam, index, hatv*16, felepit_szam + szamj * hatv) ;
}
    if ( szam[index] == 'A' ) return atalakit(szam, index, hatv*16, felepit_szam + 10 * hatv ) ;
    else if ( szam[index] == 'B' ) return atalakit(szam, index, hatv*16, felepit_szam + 11 * hatv) ;
    else if ( szam[index] == 'C' ) return atalakit(szam, index, hatv*16, felepit_szam + 12 * hatv) ;
    else if ( szam[index] == 'D' ) return atalakit(szam, index, hatv*16, felepit_szam + 13 * hatv) ;
    else if ( szam[index] == 'E' ) return atalakit(szam, index, hatv*16, felepit_szam + 14 * hatv );
    else if ( szam[index] == 'F' ) return atalakit(szam, index, hatv*16, felepit_szam + 15 * hatv ) ;
    else return felepit_szam;
}
else return felepit_szam;
}

int main(){
    string szam;
    unsigned long uj = 0, felepit_szam = 0;
    cin >> szam;
    uj = atalakit(szam, szam.length(), 1, felepit_szam);
    if ( uj == 0 && ( szam.length() > 1 || szam[szam.length() - 1] != '0') ) cout << -1;
    else cout << uj;
    return 0;
}