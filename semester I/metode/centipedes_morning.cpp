#include<iostream>
using namespace std;

int main(){
    int left, right;

    cin >> left >> right;
    cout << max((2 * right) + 40, 78 + 40 + ( left - 40 ) * 2 + 1);
}