// Egy ügyvédi irodába egyszerre érkezik n személy (1 <= n <= 1 000 000), akiknek az intéznivalóit az ügyvéd ismeri, 
// így azt is tudja, hogy egy-egy személlyel hány percet fog eltölteni (a percek száma természtes szám, legtöbb 1 000 000).
// Állapítsuk meg azt a sorrendet, amelyben fogadnia kellene a személyeket ahhoz, hogy az átlagos várakozási idő minimális legyen!
// A bemeneti állomány első sora a személyek n számát tartalmazza.
// A következő n sor mindegyike egy adott személyre szánt idő hosszát tartalmazza.
// A kimeneti állomány első sora az átlagos várakozási időt kelll tartalmazza két tizedesnyi pontossággal.
// Ezután írjuk soronként egy-egy személy sorszámát a megadott bemenet alapján, abban a sorrendben, ahogyan az ügyvédnek fogadnia kell őket.
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

void input ( int n, pii pacients[], double &average ){
    for(i, 1, n){
        cin >> pacients[i].x;
        pacients[i].y = i;
    }
    
}

void output_time ( int n, pii pacients[], double &average ){
    for (i, 1, n - 1){
        average += average + pacients[i].x;
        cout << average << endl;
    }
    average /= (double)n;
    cout << average << endl;
}

int main(){
    int n;
    double average = 0;
    cin >> n;
    pii *pacients = new pii[n + 1];
    input(n, pacients, average);
    sort(pacients + 1, pacients + n + 1);
    output_time(n, pacients, average);
    for(i, 1, n){
        cout << pacients[i].y << " ";
    }
    return 0;
}