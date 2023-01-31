// Laszlo Kazmer
// 512
// Lab8/7
// Adott egy 𝑛 karakterből álló karakterlánc, mely kizárólag az angol ábécé kis- és nagybetűit tartalmazhatja.
// Határozzuk meg, hogy hány különböző részsorozata van a megadott string-nek.
// Azokat a részsorozatokat, melyeknek ugyanaz a rész-string felel meg, csak egyszer számoljuk.
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

#define mod 1000000007

void set_vectors ( string sequence, ll n , vector < ull > &variations, int frequency[] ){
    for (i, 1, n){
        variations.pb( ( (variations[i - 1] % mod) * 2 ) % mod );
        frequency[int(sequence[i - 1])]++;
    }

}

void reduce_frequency ( int frequency[], string sequence, ll n, int target, vector < ull > &variations, ull j ){
    for( i, 0, n && frequency[j] > 1 ){
        int index = int(sequence[i]);
        if ( index == target ){
            variations[n] -= variations[i + 1] - 1;
            frequency[j]--;
        }   
    }

}

void substract ( string sequence, ll n , vector < ull > &variations, int frequency[] ){
    for (i, 97, 122){
       
        if ( frequency[i] > 1 ){
            //cout << frequency[i] <<  " " << int(sequence[i]);
            reduce_frequency(frequency, sequence, n, i, variations, i);
        }
    }
}

int main(){
    string sequence;
    cin >> sequence;
    ll n = sequence.length();
    int frequency[123] = {0};
    vector < ull > variations;
    variations.pb(1);
    set_vectors ( sequence, n, variations, frequency );
    substract(sequence, n, variations, frequency);
    cout << variations[n];
return 0;
}