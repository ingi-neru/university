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

#define for(i, a, b) for ( int i = (a); i <= (b); ++i )
#define ford(i, a, b) for( int i = (a); i >= (b); --i )
#define forn(i, n) for( int i = 0; i < (n); ++i )



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

void partitions ( int k, int solutions[], int sum, int n ){
    for (i, solutions[k - 1], sum){
        solutions[k] = i;
        if (sum - i > 0){
        partitions(k + 1, solutions, sum - i,n);
        }
        else{
            for(j, 1, k){
                cout << solutions[j] << " ";
            }
            cout << endl;
        }
    }
}

int main(){
    int n;
    cin >> n;
    int *solutions = new int[n + 1];
    solutions[0] = n;
    partitions(1, solutions, n, n);
return 0;
}