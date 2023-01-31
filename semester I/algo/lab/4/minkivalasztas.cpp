//Laszlo Kazmer
//512
//Lab4/2
//Rendezzünk egy 𝑛 elemű tömböt minimumkiválasztásra épülő rendezéssel!
#include<iostream>
using namespace std;

void minkivalasztasrendezes ( long long n, long long tomb[] ){
for ( long long i = 1; i < n; i++ ){
    long long ind_min = i;
    for ( long long j = i + 1; j <= n; j++ ){
        if ( tomb[ind_min] > tomb[j] ) ind_min = j;
    }
    swap(tomb[i],tomb[ind_min]);
}
}

void be ( long long &n, long long tomb[] ){
    cin >> n;
    for ( long long i = 1; i <= n; i++ ) cin >> tomb[i];
}

int main(){
    long long n = 1, tomb[10001] = {0};
    be(n, tomb);
    minkivalasztasrendezes(n, tomb);
    for ( long long i = 1; i <= n; i++ ) cout << tomb[i] << endl;
    return 0;
}