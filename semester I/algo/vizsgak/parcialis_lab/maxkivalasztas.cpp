#include<iostream>
using namespace std;

void maxrendezes ( long long tomb[], long long n ){

for ( long long i = n; i > 1; i-- ){
    long long maxindex = i;
    for ( long long j = i - 1; j >= 1; j-- ){
    if ( tomb[j] > tomb[maxindex] ) maxindex = j; 
    }
    swap(tomb[i], tomb[maxindex]);
}
}

void be ( long long tomb[], long long &n ){
    cin >> n;
    for ( long long i = 1; i <= n; i++ ) {
        cin >> tomb[i];
    }
}
int main(){
    long long tomb[10001] ={0}, n = 1;
    be(tomb, n);
    maxrendezes(tomb, n);
    for ( long long i = 1; i <= n; i++ ) std::cout << tomb[i] << " ";
    return 0;
}