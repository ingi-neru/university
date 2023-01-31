#include<iostream>
using namespace std;

void problem ( long long &G, long long &C ){
    long long guests;
    cin >> C;
    for ( long i = 1; i <= C; i++ ){
        
        cin >> G;
        cin >> guests;
        for ( long j = 1; j < G; j++ ){
            long pair;
            cin >> pair;
            guests = guests ^ pair;
        }
        cout << endl << "Case #" << i << ": " << guests << endl;
    }
}

int main(){
    long long G, C;
    problem(G , C);
    return 0;
}