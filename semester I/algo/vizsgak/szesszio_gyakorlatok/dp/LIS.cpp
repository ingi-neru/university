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

void print_lis ( int n, int actual[],  int arr[], int ind ){
    cout << actual[ind] << " ";
    while ( arr[ind] != -1 ){
        cout << arr[ind] << " ";
        ind = arr[ind];
    }
}

int LIS ( int n, int arr[] ){
    int *maxi = new int[n + 1];
    int *previous = new int[n + 1];
    int lis = 1;
    for (i, 1, n){
        maxi[i] = 1;
        previous[i] = -1;
    }
    for(i, 2, n){
        int subproblem = 0;
        for(j, 1, i - 1){
            if ( arr[i] > arr[j] ){
                subproblem = maxi[j];
                previous[i] = j;
            }
        }
        maxi[i] = 1 + subproblem;
        if ( maxi[i] > lis ){
            lis = i;
        }
    }
    print_lis(n, arr, previous, lis);
    cout << endl;
    return maxi[lis];
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    for (i, 1, n){
        cin >> arr[i];
    }

    cout << LIS(n, arr);
return 0;
}