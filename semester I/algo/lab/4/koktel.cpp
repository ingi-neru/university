//Laszlo Kazmer
//512
//Lab4/1
//Rendezzünk egy 𝑛 elemű tömböt koktélrendezéssel!
#include<iostream>
using namespace std;

void koktelrendezes ( long long n, long long a[] ){
long long regibal = 1, regijobb = n - 1;
bool rendben;
long long jobb, bal;
do{

rendben = true;

for ( long long i = regibal; i <= regijobb; i++ ){
    if ( a[i] > a[i + 1] ){
        swap( a[i], a[i + 1] );
        rendben = false;
        jobb = i;
    }
}
if ( !rendben ){
    regijobb = jobb;
    rendben = true;
    for ( long long i = regijobb; i >= regibal; i -- ){
        if ( a[i] > a[i + 1] ){
            swap(a[i], a[i + 1]);
            rendben = false;
            bal = i;
        }
    }
    regibal = bal;
}
}while(!rendben);
}

void be ( long long &n, long long tomb[] ){
    cin >> n;
    for ( long long i = 1; i <= n; i++ ) cin >> tomb[i];
}

int main(){
    long long n = 1, tomb[10001] = {0};
    be(n, tomb);
    koktelrendezes(n, tomb);
    for ( long long i = 1; i <= n; i++ ) cout << tomb[i] << endl;
    return 0;
}