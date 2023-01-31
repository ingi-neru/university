//Laszlo Kazmer
//512
//Lab2/7
//Adottak az elsőéves egyetemisták névsorai (abc sorrendben), csoportonként. 
//Állítsunk elő ezekből egyetlen névsort, mely szintén abc sorrendben van!

#include<iostream>
using namespace std;

void be ( unsigned long &k, unsigned long csoportszam, string nevek[][1001], string nevek_osszes[1001], unsigned long &osszes, unsigned long hosszak[] ){
    osszes = 1;
    cin >> k;
    for( unsigned long i = 1; i <= k; i++ ){
        cin >> csoportszam;
        
        hosszak[i] = csoportszam;
        for ( unsigned long j = 0; j <= csoportszam; j++ ){
        getline(cin,nevek[i][j]);
        if ( i == 1 ) nevek_osszes[j] = nevek[i][j];
    }
}
}

unsigned long szekvencialis1 ( string nevek, string nevek_osszes[], unsigned long hely, unsigned long &osszes){
    hely = 0;
    unsigned long i = 1;
    while ( hely == 0 && i <= osszes ){
        if ( nevek < nevek_osszes[i] ) hely = i;
        else i++;
    }
    return hely;
}

void valtoztat ( string nev, string nevek_osszes[1001], unsigned long &osszes ){
unsigned long hely = 0;
unsigned long k = szekvencialis1(nev, nevek_osszes, hely, osszes  );
osszes++;
if ( k == 0 ) nevek_osszes[osszes] = nev;
else{
if ( osszes > 2 ){
for ( unsigned long i = osszes; i > k; i-- ){
    nevek_osszes[i] = nevek_osszes[i - 1];
}
nevek_osszes[k] = nev;
}
else if ( nev > nevek_osszes[1] ) nevek_osszes[osszes] = nev;
else{
    nevek_osszes[2] = nevek_osszes[1], nevek_osszes[2] = nevek_osszes[1];
    nevek_osszes[1] = nev;
}
}
}
unsigned long feldolgoz ( unsigned long k, string nevek[][1001], string nevek_osszes[1001], unsigned long &osszes, unsigned long hosszak[] ){
for ( unsigned long long i = 2; i <= k; i++ ){
    for ( unsigned long long j = 1; j <= hosszak[i]; j++ ){
    valtoztat(nevek[i][j], nevek_osszes, osszes);
    }
}
return osszes;
}
int main(){
    unsigned long k=1,csoprtszam=1,osszes = 1,hosszak[11];
    string nevek[11][1001], nevek_osszes[1001];
    be(k, csoprtszam, nevek, nevek_osszes, osszes, hosszak);
    osszes = feldolgoz(k,nevek,nevek_osszes,hosszak[1],hosszak);
    for ( unsigned long i = 1; i <= osszes; i++ ){
    cout << nevek_osszes[i] << endl;
    }
    return 0;
}