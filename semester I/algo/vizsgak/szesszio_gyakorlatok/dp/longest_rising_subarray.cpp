// Adva van egy n elemű 32 bites egész számokat tartalmazó sorozat (1 <= n <= 1000).
// Határozzuk meg a leghosszabb szigorúan növekvő részsorozatának a hosszát, egy ilyen részsorozatot és a leghosszabb növekvő részsorozatok számát!
// A bemeneti állomány első sora a sorozat n hosszát tartalmazza. A következő n sor mindegyike a sorozat egy-egy elemét tartalmazza.
// A kimeneti állomány első sorába írjuk a leghosszabb növekvő részsorozat hosszát, a második sorába egy ilyen sorozatot és a harmadik sorába az ilyen részsorozatok számát!
// Pontozás: a kimenet minden sora a pontszám harmadát éri
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

void in ( int &n, int arr[] ){
cin >> n;
for(i,1,n){
    cin >> arr[i];
}
}

void print_sol(int m, int max_long[], int previous[], int arr[]){
    if ( max_long[m] > 1 ){
        print_sol(previous[m], max_long, previous, arr);
        cout << arr[m] << " ";
    }
}

void longest_subarray ( int n, int arr[] ){
    int max_long[101], previous[101] = {0}, m = 1;
    max_long[1] = 1;
    for(i, 2, n){
        max_long[i] = 0;
        for(j, 1, i - 1){
            if ( max_long[j] > max_long[i] && arr[i] > arr[j] ){
                max_long[i] = max_long[j];
                previous[i] = j;
            }
        }
        max_long[i]++;
        if ( max_long[i] > max_long[m] ){
            m = i;
        }
    }
    print_sol(m, max_long, previous, arr);
}
int main(){
    int n, array[1001];
    int subarrays[1001][1001];
    in(n, array);
    longest_subarray(n, array);
return 0;
}