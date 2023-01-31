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

void in ( int n, pii dominoes[] ){
for(i,1,n){
    cin >> dominoes[i].x >> dominoes[i].y;
}
}

void chainOfDominoes ( long n, pii d[] ){
    int regular = 0, rotated = 0, solution = 0, status[101] = {false}, nullfactor = 0;
    bool wasGreater = false, addition = false;
    for ( i, 2, n ){
        bool t = false;
        if ( regular > 0 || rotated > 0 ) wasGreater = true;
        if ( regular == 0 && rotated == 0 && wasGreater ){
            nullfactor++;
        }
        if ( d[i].x == d[i - 1].y ){
            regular++;
            t = true;
        }
        else if ( d[i].y == d[i - 1].y ){
            rotated++;
            status[i] = true;
            t = true;
        }
        else if ( d[i].x == d[i - 1].x ){
            regular++;
            t = true;
        }
        else if ( d[i].y == d[i - 1].x ){
            rotated++;
            status[i] = true;
            t = true;
        }
        if ( status[i] != status[i - 1] ){
            addition = true;
        }
        if ( !t ){
            if ( solution < max(regular, rotated) ){
            solution = max(regular, rotated);
            }
            regular = 0, rotated = 0, addition = false;
        }
        //cout << regular << " " << rotated << endl;
    }
                
                if ( solution < max(regular, rotated) ){
            solution = max(regular, rotated);
            if ( addition ){
                solution += nullfactor;
            }
            }
            cout << solution + 1 << endl;
    
    /**for ( i, 1, n){
        if ( status[i] ) cout << d[i].y << " " << d[i].x << endl;
        else cout << d[i].x << " " << d[i].y << endl;
    }**/
}

int main(){
    int n;
    cin >> n;
    pii *dominoes = new pii [n + 1];
    in(n, dominoes);
    
    //cout << endl;
    chainOfDominoes(n, dominoes);
return 0;
}