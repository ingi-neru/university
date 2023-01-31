// Laszlo Kazmer
// 512
// Lab6/4
// Adott egy 𝑛 egész szám. 
// Határozzuk meg a legkisebb olyan 𝑚 > 0 természetes számot, amelyre 𝑚 számjegyeinek szorzata egyenlő 𝑛-el!
#include<iostream>
using namespace std;

long szamjegySzorzat ( long n ){
    long i, szorzat = 0, hatv = 1;
    while ( n > 1 ){
    i = 9;
    while ( n % i != 0 ) i--;
    if ( i == 1 ) {
        return -1;
    }
    else {
        n /= i;
        szorzat += hatv * i;
        hatv *= 10;
    }
    }
    return szorzat;
}

int main(){
    long n;
    cin >> n;
    if ( n == 0 ){
        cout << "10";
    }
    else if ( n == 1 ){
        cout << "1";
    }
    else{
    cout << szamjegySzorzat(n);
    }
    return 0;
}