//Állapítsuk meg n szám közül a legkisebbet és legnagyobbat "egyidőben"! 
// Vagyis egyetlen függvényt kell írni, amely két különböző paraméterben téríti vissza a minimumot és a maximumot.
// A megállási feltételben tilos minimumot/maximumot számolni (két vagy több szám közül), ezt csak a rekurzív hívások után szabad, az algoritmus összerakási fázisában.
// A bemeneti állomány első sora a sorozat n hosszát tartalmazza (1 <= n <= 100 000). 
// A következő n sor mindegyike a sorozat egy-egy elemét tartalmazza, melyek 32 bites egész számok.
// A kimenet a példának megfelelő formátumot kell betartsa.
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

void in ( int n, int arr[] ){
    for(i, 1, n){
        cin >> arr[i];
    }
}

void print_min_max ( int n, int arr[], int left, int right, int &min, int &max ){
    int middle = ( left + right ) / 2;
    if ( left == right ){
        max = arr[left];
        min = max;
    }
    else if ( left == right - 1){
        if ( arr[left] < arr[right] ){
            min = arr[left], max = arr[right];
        }
        else{
            min = arr[right], max = arr[left];
        }
    }
    else{
        int min1 = arr[middle + 1], max1 = arr[middle + 1];
        print_min_max(n, arr, left, middle, min, max);
        print_min_max(n, arr, middle + 1, right, min1, max1);
        if ( max < max1 ) max = max1;
        if ( min > min1 ) min = min1;
    }
}

int main(){
    int n;
    cin >> n;
    int *arr = new int[n + 1];
    in(n, arr);
    int min = arr[1], max = arr[1];
    print_min_max(n, arr, 1, n, min, max);
    cout << "Minimum: " << min << endl << "Maximum: " << max ;
return 0;
}