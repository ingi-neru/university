#include<iostream>
using namespace std;

bool teamMember ( long n, bool friends[][101], long t, long team[], long j ){
    for ( long i = 1; i <= n; i++ ){
        for ( long l = 1; l <= t; l++ ){
            if ( friends[j][i] ){
                if ( i == team[l] ) return false;
            }
        }
    }
    return true;
}

void in ( long &n, bool friends[][101] ){
    long j;
    cin >> n;
    for ( long i = 1; i <= n; i++ ){
        cin >> j;
        while ( j != 0 ){
            friends[i][j] = true;
            cin >> j;
        }
    }
}

void determineTeam( long n, bool friends[][101], long &t, long team[] ){
    for ( long i = 1; i <= n; i++ ){
        if ( teamMember(n, friends, t, team, i) ){
            team[++t] = i;
        }
    }
}

int main(){
    long n , t = 0, team[101];
    bool friends[101][101] = {false};
    in(n, friends);
    determineTeam(n, friends, t, team);
    cout << t << endl;
    for ( long i = 1; i <= t; i++ ){
        cout << team[i] << " ";
    }
    return 0;
}