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

void in ( int &n, int &m, int a[], int b[] ){
cin >> n >> m;
for(i,1,n){
    cin >> a[i];
}
for(i,1,m){
    cin >> b[i];
}
}

void max_mat ( int n, int m, int a[], int b[] ){
    int mat[101][101] = {0}, max_value = 0;
    for(i, 1, n){
        for(j, 1, m){
            if ( a[i] == b[j] ){
                if ( i > 1 && j > 1 ) mat[i][j] = mat[i - 1][j - 1] + 1;
                else mat[i][j] = 1;
            }
            if( mat[i][j] > max_value ){
                max_value = mat[i][j];
            }
        }
    }
    for(i, 1, n){
        for(j, 1, m){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << max_value << endl;
}

int main(){
    int n = 2, m = 2, a[101], b[101];
    in(n, m, a, b);
    max_mat(n, m, a, b);
return 0;
}