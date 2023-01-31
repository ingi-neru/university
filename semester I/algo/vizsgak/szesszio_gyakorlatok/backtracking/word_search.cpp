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

void word_search ( int k, int m, int n, int poz_x, int poz_y, char board[][10], string searched, bool was[][10] ){
    if ( k == searched.length() ){
        was[9][9] = true;
        cout << "true";
        exit(0);
    }
    else{
        if ( board[poz_x][poz_y] == searched[k] ){
            if ( poz_x > 1 ){
                if ( board[poz_x - 1][poz_y] == searched[k + 1] && !was[poz_x - 1][poz_y]){

                    was[poz_x - 1][poz_y] = true;
                    word_search(k + 1, m, n, poz_x - 1, poz_y, board, searched, was);
                    was[poz_x - 1][poz_y] = false; 
                }
            }    
                    if ( poz_y > 1 ){
                if ( board[poz_x][poz_y - 1] == searched[k + 1] && !was[poz_x][poz_y - 1]){
                    was[poz_x][poz_y - 1] = true;
                    word_search(k + 1, m, n, poz_x, poz_y - 1, board, searched, was);
                    was[poz_x][poz_y - 1] = false; 
                }
                }
                    if ( poz_x < n ){
                if ( board[poz_x + 1][poz_y] == searched[k + 1] && !was[poz_x + 1][poz_y]){
                    was[poz_x + 1][poz_y] = true;
                    word_search(k + 1, m, n, poz_x + 1, poz_y, board, searched, was);
                    was[poz_x + 1][poz_y] = false; 
                }
                }
                    if ( poz_y < n ){
                if ( board[poz_x][poz_y + 1] == searched[k + 1] && !was[poz_x][poz_y + 1]){
                    was[poz_x][poz_y + 1] = true;
                    word_search(k + 1, m, n, poz_x, poz_y + 1, board, searched, was);
                    was[poz_x][poz_y + 1] = false; 
                }
            }
            
            
        }
    }
}

void word ( int m, int n, string searched, char board[][10] ){
    bool was[10][10] = {false};
    for(i, 1, m){
        for(j, 1, n){
            was[i][j] = true;
            word_search(0, m, n, i, j, board, searched, was);
            cout << endl;
            was[i][j] = false;
        }
    }
    if ( !was[9][9] ){
        cout << "false";
    }
}

int main(){
    int m, n;
    bool was[10][10];
    char board[10][10];
    string searched;
    cin >> m >> n;
    for (i, 1, m){
        for(j, 1, n){
            cin >> board[i][j];
        }
    }
    cin >> searched;
    word(m, n, searched, board);
return 0;
}