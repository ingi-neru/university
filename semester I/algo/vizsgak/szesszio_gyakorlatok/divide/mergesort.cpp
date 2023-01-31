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



void merge ( int n, int arr[], int left, int middle, int right ){
    int aux_a[101], aux_b[101], a_length = 0, b_length = 0;
    for (i, left, middle){
        aux_a[++a_length] = arr[i];
    }

    for (i, middle + 1, right){
        aux_b[++b_length] = arr[i];
    }

    aux_a[a_length + 1] = INT_MAX, aux_b[b_length + 1] = INT_MAX;
    int aux[101], i = 1, j = 1, index = 0;
    while (i <= a_length || j <= b_length ){
        if ( aux_a[i] < aux_b[j] ){
            aux[++index] = aux_a[i];
            i++;
        }
        else if ( aux_a[i] == aux_b[j] ){
            aux[++index] = aux_a[i];
            i++, j++;
        }
        else{
            aux[++index] = aux_b[j];
            j++;
        }
    }
    i = 1;
    for (j, left, right){
        arr[j] = aux[i];
        i++;
    }
}

void mergesort ( int n, int arr[], int left, int right ){
    if ( left < right ){
    int middle = ( left + right ) / 2;
    mergesort(n, arr, left, middle);
    mergesort(n, arr, middle + 1, right);
    merge(n, arr, left, middle, right);
    }
}


int main(){
    int n = 5, arr[101] = {-1, 1, -7, 5, 3, -2};
    mergesort(n, arr, 1, n);
    for (i, 1, n){
        cout << arr[i] << " ";
    }
return 0;
}