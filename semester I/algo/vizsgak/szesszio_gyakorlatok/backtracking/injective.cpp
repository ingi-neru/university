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

void output_sol(int n, int solution[]){
    for(i, 1, n){
        cout << solution[i] << " ";
    }
    cout << endl;
}


void injective ( int k, int n, int m, int solution[], bool was[] ){
    if ( k == n + 1 ){
        output_sol(n, solution);
    }
    else{
        for (i, 1, m){
            if ( !was[i] ){
                was[i] = true;
                solution[k] = i;
                injective(k + 1, n, m, solution, was);
                was[i] = false;
            }
        }
    }
}

int main(){
    int n, m, solution[101];
    cin >> n >> m;
    bool was[101] = {false};
    injective(1, n, m, solution, was);
return 0;
}