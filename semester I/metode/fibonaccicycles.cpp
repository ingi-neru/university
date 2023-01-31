#include<iostream>
using namespace std;

void firstReappearance ( long Q, long long queries[] ){
    for ( int i = 1; i <= Q; i++ ){
    long k = queries[i];
    long long f1 = 1, f2 = 1, f3, j = 1, first = -1;
    pair < bool, long long > appeared[1002];

    for ( long long j = 1; j <= k + 1; j++ ){
        appeared[j].first = false;
    }

    while ( j <= k + 1 && first == -1 ){
        f3 = ( f1 + f2 ) % k ;
        f1 = f2;
        f2 = f3;
        //cout << f3 << " ";
        if ( appeared[f3].first ){
            first = appeared[f3].second + 1;
        }
        else{
            appeared[f3].first = true;
            appeared[f3].second = j;
        }
        j++;
    }
    cout << first << endl;
    }
}


void in ( long &Q, long long queries[] ){
    cin >> Q;
    for ( long i = 1; i <= Q; i++ ){
        cin >> queries[i];
    }

}

int main(){
    long Q;
    long long queries[501];
    in(Q, queries);
    firstReappearance(Q, queries);
    return 0;
}