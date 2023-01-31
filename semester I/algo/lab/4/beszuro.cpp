//Laszlo Kazmer
//512
//Lab4/1
//Rendezzünk egy 𝑛 elemű tömböt beszúró rendezéssel!
#include<iostream>
using namespace std;

void beszurorendezes ( long long n, long long tomb[] ){
    for ( long long j = 2; j <= n; j++ ){
    long long seged = tomb[j], i = j - 1;
    while ( i > 0 && tomb[i] > seged ){
        tomb[i + 1] = tomb[i];
        i--;
    }
    tomb[i + 1] = seged;
    }
}

void be ( long long &n, long long tomb[] ){
    cin >> n;
    for ( long long i = 1; i <= n; i++ ) cin >> tomb[i];
}

int main(){
    long long n = 1, tomb[10001] = {0};
    be(n, tomb);
    beszurorendezes(n, tomb);
    for ( long long i = 1; i <= n; i++ ) cout << tomb[i] << endl;
    return 0;
}