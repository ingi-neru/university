#include<iostream>
using namespace std;

bool megoldhato (long i, long &nyitott, long &zart, string zarojelek ){
    if ( zart > nyitott ){
        return false;
    }
    if ( i == zarojelek.length() ){
    if ( nyitott != zart ){
    return false;
    }
    else{
        return true;
    }
    }
    if ( zarojelek[i] == ')' ){
        zart++;
    }
    else if ( zarojelek[i] == '(' ){
        nyitott++;
    }
    return megoldhato(i + 1, nyitott, zart, zarojelek);
}

int main(){
    long nyitott = 0, zart = 0;
    string zarojelek;
    cin >> zarojelek;
    if ( megoldhato(0, nyitott, zart, zarojelek) ) cout << "megoldhato";
    else cout << "nem megoldhato";
    return 0;
}