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
#define rs resize
#define pb push_back
#define all(x) x.begin(), x.end()
#define ins insert
#define er erase
#define cnt count

int power( int num, int p ){
    int og = num;
    for (i, 1, p - 1){
        og *= num;
    }
    return og;
}

int mul ( int x, int y, int n ){
    if ( n == 1 ){
        return x * y;
    }
    else{
        int m = n / 2, a, b, c, d, e, f, g, h;
        a = x / power(10, m);
        b = x % power(10, m);
        c = y / power(10, m);
        d = y % power(10, m);
        e = mul(a, c, m);
        f = mul(b, d, m);
        g = mul(b, c, m);
        h = mul(a, d, m);
        return power(10, 2 * m) * e + power(10, m) * (g + h) + f;
    }
}

int main(){
    int a = 10, b = 12, n = 2;
    cout << mul(a, b, n);
return 0;
}