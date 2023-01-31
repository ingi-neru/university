// Laszlo Kazmer
// 512
// Lab8/9
//A virágüzlet ablakában 𝑣 váza áll, melyekbe 𝑓 csokor virágot szeretnénk elhelyezni.
// A vázákat nem mozdíthatjuk el és a sorszámuk megadja, hogy hogyan helyeszkednek el balról jobbra. 
// A virágcsokrok sorszáma megadja, hogy egymáshoz képést hogyan kell elhelyeznünk őket, vagyis egy 𝑖 virágcsokor mindig egy 𝑗 virágcsokor baloldalán kell legyen, ha 𝑖 < 𝑗. 
// Ha ismerjük, hogy egy adott virágcsokor egy adott vázába helyezve milyen esztétikai értéket nyújt, határozzuk meg a maximális esztétikai értéket, amelyet elérhetünk és egy olyan elhelyezést, amely ezt lehetővé teszi!
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

void in ( int &n, int &m,int mat[][101]){
cin >> n >> m;
for(i,1,n){
    for(j,1,m){
    cin >> mat[i][j];
    }
  }
}

int main(){
    int n, m;
    int vases[101][101];
    in(n, m, vases);
return 0;
}