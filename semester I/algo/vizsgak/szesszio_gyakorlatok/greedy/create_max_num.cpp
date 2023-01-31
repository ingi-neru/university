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
#define ford(i, a, b) for( int i = (a); i>= (b); --i )

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

void input ( int &n, int &m, int nums1[], int nums2[], int &k ){
    int maxi = 0;
    cin >> n;
    for (i, 1, n){
        cin >> nums1[i];
    }
    maxi = 0;
    cin >> m;
    for(i, 1, m){
        cin >> nums2[i];
    }
    cin >> k;
}

int find_next_num ( int n, int a[], bool was[] ){
    int maxi = 0, ind = 0;
    for(i, 1, n){
        if ( a[i] > maxi && !was[i] ){
            maxi = a[i];
            ind = i;
        }
    }
    return ind;
}

void create_max ( int n, int m, int nums1[], int nums2[], int k ){
    int solution[101];
    bool was1[101] = {0}, was2[101] = {0};
    
}

int main(){
    int nums1[101], nums2[101];
    int i1 = 1, i2 = 1, n, m, k;
    input(n, m, nums1, nums2, k);
    create_max(n, m, nums1, nums2, k);
return 0;
}