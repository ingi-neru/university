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
pii start;

int row[8] = {2, 1, -1, -2, -2, -1, 1, 2 };
int col[8] = {1, 2, 2, 1, -1, -2, -2, -1 };

void in ( int &n, pii &start ){
    cin >> n;
    cin >> start.x >> start.y;
}

void print_route(vpii solution, int sizer){
    for(i, 0, solution.size() - 1){
        cout << solution[i].x << " " << solution[i].y << endl;
    }
}

bool isValid ( int n, int coordinate_x, int coordinate_y, bool table[][21] ){
    return ( coordinate_x > 0 && coordinate_x <= n && coordinate_y > 0 && coordinate_y <= n && !table[coordinate_x][coordinate_y] );
}

void backtrack_steps ( int n, pii position, bool table[][21], vpii &solution, int &size ){
    cout << position.x << " "  << position.y << endl;
    for (i,1,n){
        for(j, 1, n){
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    if ( size == n * n - 1 ){
        
        print_route(solution, size);
        exit(0);
    }
    else{
        bool cant_continue = true;
        for (i, 0, 7){
            if ( isValid(n, position.x + row[i], position.y + col[i], table) ){
                cant_continue = false;
                position.x += row[i];
                position.y += col[i];
                solution.pb(position);
                table[position.x][position.y] = true;
                size++;
                backtrack_steps(n, position, table, solution, size);
                table[position.x][position.y] = false;
                solution.pop_back();
                size--;
            }
                
        }
    }
}

int main(){
    int n, num = 0;
    pii position;
    vpii solution;
    bool table[21][21] = {false};
    in(n, position);
    table[position.x][position.y] = true;
    backtrack_steps(n, position, table, solution, num);
    if ( num == 0 ){
        cout << "No solution";
    }
return 0;
}