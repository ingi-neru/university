// Románia n városának mindegyike össze van kötve legalább n / 2 másik várossal egy direkt kétirányú úttal (1 <= n <= 100).
// Határozzuk meg az összes olyan útvonalat, amely Kolozsvárról indul és oda ér vissza és a többi várost pontosan egyszer érinti.
// A bemeneti állomány első sora tartalmazza a városok n és az összeköttetések m számát.
// A következő m sor mindegyikében két város neve található egy szóközzel elválasztva.
// Egy város neve legtöbb 50 karakter hosszú.
// A kimeneti állományba írjunk soronként egy-egy olyan útvonalat, amely megfelel a követelményeknek. Az útvonalakat bármilyen sorrendben fel lehet sorolni.
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

void in ( int &n, int &m, pair < string, string > cities[] ){
    cin >> n >> m;
    for(i, 1, m){
        cin >> cities[i].x >> cities[i].y;
    }
}

void backtrack_connections ( int k, int n, int m, string route[], pair < string, string > cities[], bool was[] ){
    if ( k == n + 1 ){
        for (i, 1, n){
            cout << route[i] << " ";
        }
        cout << "Kolozsvar" << endl;
    }
    else{
        for (i, 1, n){
            if ( cities[i].x == route[k - 1] && !was[i] ){
                route[k] = cities[i].y;
                was[i] = true;
                backtrack_connections(k + 1, n, m, route, cities, was);
                was[i] = false;
            }
            else if ( cities[i].y == route[k - 1] && !was[i] ){
                route[k] = cities[i].x;
                was[i] = true;
                backtrack_connections(k + 1, n, m, route, cities, was);
                was[i] = false;
            }
        }
    }
}

int main(){
    bool was[101] = {false};
    int n, m;
    pair < string, string > cities[101];
    string routes[101];
    routes[1] = "Kolozsvar";
    in(n, m, cities);
    backtrack_connections(2, n, m, routes, cities, was);
return 0;
}