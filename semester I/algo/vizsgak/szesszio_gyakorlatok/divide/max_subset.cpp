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

void max_subset ( int n, int arr[], int left, int right, int &sol ){
    if ( left <= right ){
        int mid = ( left + right ) / 2;
        if ( left == right ){
            if ( arr[left] > 0 ) 
            sol += arr[left];
        }
        else if ( left == right - 1 ){
            if ( sol < arr[left] + arr[right] ){
            sol += arr[left] + arr[right];
            }
            else if( sol + arr[left] + arr[right] > sol ){
                sol += arr[left] + arr[right];
            }
            
        }
        else{
        int max1 = 0;
        max_subset(n, arr, left, mid, sol);
        max_subset(n, arr, mid + 1, right, max1);
        if ( sol < max1 ) sol += max1;
        }
    }
}

int main(){
    int n = 8, arr[10] = {-1, 1 ,2 ,-1 ,2 ,-10 ,3 ,4 ,-1}, sol = 0;
    max_subset(n, arr, 1, n, sol);
    cout << sol;
return 0;
}