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
#define ford(i, a, b) for( int i = (a); i>= (b); --i )

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

    void max_value ( int n, int s, pii arr[], int dp[][101] ){
        for(i, 1, n){
            for(j, 1, s){
                if ( arr[i].y <= j ){
                if( arr[i].x + dp[i - 1][j - arr[i].y] > dp[i - 1][j] ){
                    //cout << i << " " << j << " " << arr[i].y << " " << endl;
                    dp[i][j] = arr[i].x + dp[i - 1][j - arr[i].y];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
                for(i, 1, n){
            for(j, 1, s){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }

int main(){
    int n, s, dp[101][101] = {0};
    cin >> n;
    pii *arr = new pii[n + 1];
    for (i, 1, n){
        cin >> arr[i].x >> arr[i].y;
    }
    cin >> s;
    max_value(n, s, arr, dp);
return 0;
}