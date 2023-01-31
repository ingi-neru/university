// Laszlo Kazmer
// 512
// Lab8/3
// Adott 𝑛 dominó. 
// Határozzuk meg a leghosszabb olyan sorozatot, mely közvetlenül egymás után következő dominókból áll és betartja a dominó játék szabályait.
// A dominókat el lehet forgatni 180 fokkal.
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

void in ( int n, pii pairs[] ){
for(i,1,n){
    cin >> pairs[i].x >> pairs[i].y;
}
}

long checkAll ( pii pairs[], int i ){
    if ( pairs[i].x == pairs[i - 1].x || pairs[i].x == pairs[i - 1].y ){
        return pairs[i].y;
    }
    else if ( pairs[i].y == pairs[i - 1].x || pairs[i].y == pairs[i - 1].y ){
        return pairs[i].x;
    }
    return 0;
}

int chainOfDominoes ( int n, pii pairs[] ){
    int longestChain = 1, actualChain = 1, next = 0;
    for (i, 2, n){
        bool continous = false, len = false;
        if ( longestChain < actualChain ){
                longestChain = actualChain;
        }
        if ( actualChain == 1 ){
            next = checkAll(pairs, i);
        }
        if ( next != 0 ){
            continous = false;
            if ( pairs[i].y == next ){
                if ( actualChain != 1 ){
                    next = pairs[i].x;
                }
                actualChain++;
                continous = true;
            }
            else if ( pairs[i].x == next ){
                if ( actualChain != 1 ){
                next = pairs[i].y;
                }
                actualChain++;
                continous = true;
            }
        }
        if ( !continous ) {
            actualChain = 1;
        }
        //cout << actualChain << " " << pairs[i].x << " " << pairs[i].y << " " << next << endl << endl;
    }
    if ( longestChain < actualChain ){
                longestChain = actualChain;
        }
    return longestChain;
}

int main(){
    int n, solution;
    cin >> n;
    pii *pairs = new pii[n + 1];
    in(n, pairs);
    //cout << endl;
    solution = chainOfDominoes(n, pairs);
    swap(pairs[2].x, pairs[2].y);
    //cout << solution << endl;
    solution = max(solution, chainOfDominoes(n, pairs));
    cout << solution;
return 0;
}