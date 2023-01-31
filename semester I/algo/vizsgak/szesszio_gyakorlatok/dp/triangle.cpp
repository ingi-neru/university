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

void in ( int &n, int mat[][1001] ){
cin >> n;
for(i, 1, n){
    for(j, 1, i){
    cin >> mat[i][j];
    }
  }
}

void calculate_min ( int n, int mat[][1001], string path[] ){
    for (i, 2, n){
        path[i] = "";
        for(j, 1, i){
            if ( j == i ){
                mat[i][j] += mat[i - 1][j - 1];
                path[i] += "J";
            }
            else if ( j > 1 ){
                if ( mat[i - 1][j - 1] < mat[i - 1][j] ){
                    mat[i][j] += mat[i - 1][j - 1];
                    path[i] += "J";
                }
                else{
                    mat[i][j] += mat[i - 1][j];
                    path[i] += 'B';
                }
            }
            else{
                    mat[i][j] += mat[i - 1][j];
                    path[i] += 'B';
            }
        }
    }
}

int maxkivalaszt2 ( int n, int mat[][1001], int place ){
    place = 1;
    for (i, 2, n){
        if ( mat[n][i] < mat[n][place] ) place = i;
    }
    return place;
}

void get_path ( int n, string path[], string &route, int place ){
    int j = place - 1, i = n;
    while ( i >= 1 ){
        route += path[i][j];
        if ( path[i][j] == 'J' ){
            j--;
        }
        i--;
    }
}

int main(){
    int n, mat[1001][1001], place;
    string path[1001], route = "";
    in(n, mat);
    calculate_min(n, mat, path);
    place = maxkivalaszt2(n, mat, 1);
    cout << mat[n][place] << endl;
    get_path(n, path, route, place);
    int i = route.length() - 1;
    while ( i >= 0 ){
        cout << route[i];
        i--;
    }
return 0;
}