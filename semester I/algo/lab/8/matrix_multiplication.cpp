// Laszlo Kazmer
// 512
// Lab8/8
//Adott 𝑛 mátrix, melyeket össze lehet szorozni az adott sorrendben.
// Állapítsuk meg a szorzásukhoz szükséges skalárszorzatok minimális számát és egy optimális zárójelezést!
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
#define vpii vector < pair<int, int>>
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

void in ( int &n, pair < long long, long long > dimensions[101] ){
    cin >> n;
    for(i, 1, n){
        cin >> dimensions[i].x >> dimensions[i].y;
    }
}

void set_matrix_pdf (int n, pair < long long, long long > dimensions[], ll mat[][101] ){
        for ( i, 1, n ){
            mat[i][i] = 0;
        }
        int i = n;
        while ( i >= 1 ){
            for( j, i + 1, n){
                ll multi = 0;
                mat[i][j] = LLONG_MAX;
                for ( k, i, j - 1){
                    if ( ( mat[i][k] + mat[k + 1][j] + dimensions[i].x * dimensions[k].y * dimensions[j].y ) < mat[i][j] ){
                        multi = mat[i][k] + mat[k + 1][j] + dimensions[i].x * dimensions[k].y * dimensions[j].y;
                        mat[i][j] = multi;
                        mat[j][i] = k;
                    }
                }
            }
        i--;
        }
        cout << mat[1][n];
}

void print_brackets(int i, int j, ll mat[][101]){
    if ( i == j ){
        cout << i;
    }
    else{
        cout << "(";
        print_brackets(i, mat[j][i], mat);
        cout << "x";
        print_brackets(mat[j][i] + 1, j, mat);
        cout << ")";
    }
}
int main(){
    int n;
    pair < long long, long long > dimensions[101];
    ll multiplications[101][101];
    in(n, dimensions);
    set_matrix_pdf(n, dimensions, multiplications);
    cout << endl;
    print_brackets(1, n, multiplications);
    return 0;
}