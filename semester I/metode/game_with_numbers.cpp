#include<iostream>
using namespace std;

void megold ( long long n ){
    if ( n % 10 == 0 ){
        cout << 2;
    }
    else{
        cout << 1 << endl << n % 10;
    }
}

int main(){
    long long n;
    cin >> n;
    megold(n);
    return 0;
}