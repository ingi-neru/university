#include <vector>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <bitset>
#include <stack>
#include <list>

#include <numeric>
#include <algorithm>
#include <random>
#include <chrono>

#include <cstdio>
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <climits>

#include <cctype>
#include <cmath>
#include <ctime>
#include <cassert>

using namespace std;

#define ull unsigned long long
#define ll long long
#define pii pair <int, int>
#define pll pair <long, long>
#define vb vector <bool>
#define vi vector <int>
#define vll vector <ll>
#define vd vector <double>
#define vs vector <string>
#define vpii vector < pair<int, int> >
#define vvi vector <vi>
#define vvb vector <vb>
#define si set <int>
#define usi unordered_set <int>
#define mii map <int, int>
#define umii unordered_map <int, int>
#define ms multiset
#define us unordered_set
#define um unordered_map
#define ums unordered_multiset
#define umm unordered_multimap

#define forn(i, n) for( int i = 0; i < (n); ++i )
#define for(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford for( int i = (a); i>= (b); --i )

#define sz size()
#define bg begin()
#define en end()
#define cl clear()
#define x first
#define y second
#define rs resize
#define pb push_back
#define all(x) x.begin(), x.end()
#define ins insert
#define er erase
#define cnt count

void in ( string &start, string &destination ){
    cin >> start >> destination;
}

void construct_matrix ( string start, string destination, int dp[][101] ){
    int n = start.length(), m = destination.length();
    for(i, 0, n){
        dp[0][i] = i;
    }
    for(i, 0, m){
        dp[i][0] = i;
    }
    for (i, 1, m){
        for(j, 1, n){
            if ( start[j - 1] != destination[i - 1]){
                //cout << start[j - 1] << " " << destination[i - 1] << endl;
                dp[i][j] = min(dp[i - 1][j], min( dp[i][j - 1], dp[i - 1][j - 1] ) ) + 1;
            }
            else{
                cout << start[j - 1] << " " << destination[i - 1] << " " << i << " " << j << endl;
                dp[i][j] = dp[i - 1][j - 1];
            }
        }
    }
    for(i, 0, m){
        for(j, 0, n){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    string start, destination;
    int numOfChanges[101][101];
    in(start, destination);
    construct_matrix(start, destination, numOfChanges);
return 0;
}